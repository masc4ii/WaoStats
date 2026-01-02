#include "TourDataPlot.h"

TourDataPlot::TourDataPlot( QWidget *parent )
: QCustomPlot( parent )
{
    addLayer( "trackerLayer", 0, QCustomPlot::limAbove );
    m_trackerLayer = layer( "trackerLayer" );
    m_trackerLayer->setMode( QCPLayer::lmBuffered );

    init();
    replot();
    connect( this,   SIGNAL( mouseMove( QMouseEvent* ) ), this, SLOT( mouseOverPlot( QMouseEvent* ) ) );
    connect( xAxis,  SIGNAL( rangeChanged( QCPRange ) ),  this, SLOT( onXRangeChanged( QCPRange ) ) );
    connect( yAxis,  SIGNAL( rangeChanged( QCPRange ) ),  this, SLOT( onY1RangeChanged( QCPRange ) ) );
    connect( yAxis2, SIGNAL( rangeChanged( QCPRange ) ),  this, SLOT( onY2RangeChanged( QCPRange ) ) );

    QCustomPlot::setInteraction( QCP::iRangeDrag, true );
    QCustomPlot::setInteraction( QCP::iRangeZoom, true );
    QList<QCPAxis *> draggableAxes = { xAxis,yAxis,yAxis2 };
    axisRect()->setRangeDragAxes( draggableAxes );
    axisRect()->setRangeZoomAxes( draggableAxes );
    //setNotAntialiasedElements(QCP::AntialiasedElement::aeNone);
}

void TourDataPlot::init()
{
    setBackground( QBrush( QColor( 0, 0, 0, 0 ) ) );
    axisRect(0)->setBackground( QBrush( QColor( 255, 255, 255 ) ) );
    axisRect(0)->setMargins( QMargins( 0, 0, 0, 0 ) );
    xAxis->setPadding( 0 );
    xAxis2->setPadding( 0 );
    yAxis->setPadding( 0 );
    yAxis2->setPadding( 0 );

    //Font
    QFont font = xAxis->labelFont();
#ifdef __APPLE__
    font.setPointSize( 10 );
#endif
    //Darkmode font color
    if( palette().background().color().redF() < 0.5 )
    {
        xAxis->setLabelColor( Qt::white );
        yAxis->setLabelColor( Qt::white );
        yAxis2->setLabelColor( Qt::white );
        xAxis->setTickLabelColor( Qt::white );
        yAxis->setTickLabelColor( Qt::white );
        yAxis2->setTickLabelColor( Qt::white );
        xAxis->setTickPen( QPen( Qt::gray ) );
        yAxis->setTickPen( QPen( Qt::gray ) );
        yAxis2->setTickPen( QPen( Qt::gray ) );
        xAxis->setSubTickPen( QPen( Qt::gray ) );
        yAxis->setSubTickPen( QPen( Qt::gray ) );
        yAxis2->setSubTickPen( QPen( Qt::gray ) );
        axisRect(0)->setBackground( QColor( 64, 64, 64 ) );
    }

    //X Axis and grid
    xAxis->setLabelFont( font );
    xAxis->setTickLabelFont( font );
    xAxis->grid()->setSubGridVisible( true );
    xAxis->grid()->setPen( QPen( Qt::lightGray, 0, Qt::SolidLine ) );
    xAxis->grid()->setSubGridPen( QPen( Qt::lightGray, 0, Qt::DotLine ) );
    xAxis->setTickLength( 0, 8 );
    xAxis->setSubTickLength( 0, 4 );
    xAxis->setLabelPadding( 0 );
    xAxis->setTickLabelPadding( 0 );
    xAxis->setOffset( 2 );

    //Y Axis left and grid
    yAxis->setLabelFont( font );
    yAxis->setTickLabelFont( font );
    yAxis->grid()->setSubGridVisible( true );
    yAxis->grid()->setPen( QPen( Qt::lightGray, 0, Qt::SolidLine ) );
    yAxis->grid()->setSubGridPen( QPen( Qt::lightGray, 0, Qt::DotLine ) );
    yAxis->setTickLength( 0, 8 );
    yAxis->setSubTickLength( 0, 4 );
    yAxis->setLabelPadding( 5 );
    yAxis->setTickLabelPadding( 0 );
    yAxis->setOffset( 2 );

    //Y axis right
    yAxis2->setLabelFont( font );
    yAxis2->setTickLabelFont( font );
    yAxis2->setVisible( true );
    yAxis2->setTickLength( 0, 8 );
    yAxis2->setSubTickLength( 0, 4 );
    yAxis2->setLabelPadding( 5 );
    yAxis2->setTickLabelPadding( 0 );
    yAxis2->setOffset( 2 );

    //Fixed labels
    if( m_xType == Distance ) xAxis->setLabel( tr( "Distance [km]" ) );
    else                      xAxis->setLabel( tr( "Time [hh:mm]" ) );
    yAxis->setLabel( tr( "Altitude [m]" ) );

    //Main Curves
    addGraph();
    graph( AltitudeCurve )->rescaleAxes();
    graph( AltitudeCurve )->setPen( QPen( Qt::red, m_graphWidth ) );
    graph( AltitudeCurve )->setBrush( QBrush( QColor( 255, 0, 0, 25 ) ) );
    graph( AltitudeCurve )->setName( tr( "Altitude [m]" ) );

    addGraph();
    graph( AltitudeLowerBound )->setPen(Qt::NoPen);
    graph( AltitudeCurve )->setChannelFillGraph( graph( AltitudeLowerBound ) );

    addGraph( xAxis, yAxis2 );
    //graph( Free2ndCurve )->rescaleAxes();
    graph( Free2ndCurve )->setPen( QPen( QColor( 0, 180, 0 ), m_graphWidth ) );

    addGraph( xAxis, yAxis2 );
    //graph( Free3rdCurve )->rescaleAxes();
    graph( Free3rdCurve )->setPen( QPen( QColor( 100, 205, 255 ), m_graphWidth ) );

    addGraph( xAxis, yAxis2 );
    //graph( Free4thCurve )->rescaleAxes();
    graph( Free4thCurve )->setPen( QPen( QColor( 255, 200, 0 ), m_graphWidth ) );

    switch( m_yType )
    {
    case Speed:
        yAxis2->setLabel( tr( "Speed [km/h]" ) );
        graph( Free2ndCurve )->setName( tr( "Speed [km/h]" ) );
        break;
    case DeviceBattery:
        yAxis2->setLabel( tr( "Device Battery [%]" ) );
        graph( Free2ndCurve )->setName( tr( "Device Battery [%]" ) );
        break;
    case Cadence:
        yAxis2->setLabel( tr( "Cadence [rpm]" ) );
        graph( Free2ndCurve )->setName( tr( "Cadence [rpm]" ) );
        break;
    case Temperature:
        yAxis2->setLabel( tr( "Temperature [°C]" ) );
            graph( Free2ndCurve )->setName( tr( "Temperature [°C]" ) );
            break;
    case Grade:
        yAxis2->setLabel( tr( "Grade [%]" ) );
        graph( Free2ndCurve )->setName( tr( "Grade [%]" ) );
        break;
    case HeartRate:
        yAxis2->setLabel( tr( "Heart Rate [bpm]" ) );
        graph( Free2ndCurve )->setName( tr( "Heart Rate [bpm]" ) );
        break;
    case Calories:
        yAxis2->setLabel( tr( "Calories [kcal]" ) );
        graph( Free2ndCurve )->setName( tr( "Calories [kcal]" ) );
        break;
    case Power:
        yAxis2->setLabel( tr( "Power [W]" ) );
        graph( Free2ndCurve )->setName( tr( "Power [W]" ) );
        break;
    case LRBalance:
        yAxis2->setLabel( tr( "L/R Balance" ) );
        graph( Free2ndCurve )->setName( tr( "L/R Balance" ) );
        break;
    case PedalSmoothness:
        yAxis2->setLabel( tr( "Pedal Smoothness [%]" ) );
        graph( Free2ndCurve )->setName( tr( "Left" ) );
        graph( Free3rdCurve )->setName( tr( "Right" ) );
        break;
    case GearInfo:
        yAxis2->setLabel( tr( "Gear Ratio / Gear Number" ) );
        graph( Free2ndCurve )->setName( tr( "Gear Ratio" ) );
        graph( Free3rdCurve )->setName( tr( "Gear Front" ) );
        graph( Free4thCurve )->setName( tr( "Gear Rear" ) );
        break;
    case GpsAccuracy:
        yAxis2->setLabel( tr( "GPS Accuracy [m]" ) );
        graph( Free2ndCurve )->setName( tr( "GPS Accuracy [m]" ) );
        break;
    case WindSpeed:
        yAxis2->setLabel( tr( "Wind Speed [km/h]" ) );
        graph( Free2ndCurve )->setName( tr( "Wind Speed [km/h]" ) );
        break;
    case AirSpeed:
        yAxis2->setLabel( tr( "Air Speed [km/h]" ) );
        graph( Free2ndCurve )->setName( tr( "Air Speed [km/h]" ) );
        break;
    }

    //Average Line
    addGraph( xAxis, yAxis2 );
    graph( AverageLine )->setPen( QPen( Qt::darkGray, m_lineWidth, Qt::DashDotLine ) );
    graph( AverageLine )->setVisible( m_avgOn );

    //Tracker Line in its own layer for speedup
    addGraph( xAxis, yAxis );
    graph( TrackerLine )->setLayer( m_trackerLayer );
    graph( TrackerLine )->setPen( QPen( Qt::lightGray, m_lineWidth ) );
}

void TourDataPlot::drawPlots( TourData *pTourData, ePlotXType xType, ePlotYType yType )
{
    if( pTourData->getTourDistance().size() < 2 )
        return;

    m_xType = xType;
    m_yType = yType;

    m_plotted = false;

    clearGraphs();
    foreach( QCPItemText* label, m_lapLabels ) removeItem( label );
    m_lapLabels.clear();
    init();

    m_tourTimeStamp.clear();
    foreach( double time, pTourData->getTourTimeStamp() )
    {
        m_tourTimeStamp.append( tourTimeToPlotTime( time ) );
    }
    m_gearTimeStamp.clear();
    foreach( double time, pTourData->getGearTimeStamp() )
    {
        m_gearTimeStamp.append( tourTimeToPlotTime( time ) );
    }

    //Altitude curve, and setup x axis for time if needed
    if( xType == Distance )
    {
        graph( AltitudeCurve )->setData( pTourData->getTourDistance(), pTourData->getTourAltitude() );
        graph( AltitudeLowerBound )->setData( pTourData->getTourDistance(), QVector<double>(pTourData->getTourDistance().size(), -1e6) );
        QSharedPointer<QCPAxisTicker> stdTicker( new QCPAxisTicker );
        xAxis->setTicker( stdTicker );
        xAxis->setRange( pTourData->getTourDistance().first(), pTourData->getTourDistance().last() );
    }
    else
    {
        graph( AltitudeCurve )->setData( m_tourTimeStamp, pTourData->getTourAltitude() );
        graph( AltitudeLowerBound )->setData( m_tourTimeStamp, QVector<double>(m_tourTimeStamp.size(), -1e6) );
        QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
        dateTimeTicker->setDateTimeFormat("hh:mm");
        xAxis->setTicker(dateTimeTicker);
        xAxis->setRange( m_tourTimeStamp.first(), m_tourTimeStamp.last() );
    }
    //Manual scale for altitude. If no altitude data available, autoscale centers the 0m-line
    if( ( ( (int)pTourData->getSession().ascent != 0 ) && ( (int)pTourData->getSession().descent != 0 ) ) )
    {
        yAxis->setRange( pTourData->getSession().altitudeMin - 10, pTourData->getSession().altitudeMax + 10 );
        yAxis->coordToPixel( yAxis->range().lower );
    }
    else graph( AltitudeCurve )->rescaleAxes();

    //Prepare average line
    QVector<double> xAvg;
    QVector<double> yAvg = { 0, 0 };
    if( xType == Distance ) xAvg = { pTourData->getTourDistance().first(), pTourData->getTourDistance().last() };
    else xAvg = { m_tourTimeStamp.first(), m_tourTimeStamp.last() };

    switch( yType )
    {
    case Speed:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourSpeed() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourSpeed() );
        yAvg = { pTourData->getSession().avgSpeed * 3.6, pTourData->getSession().avgSpeed * 3.6 };
        graph( AverageLine )->setData( xAvg, yAvg );
        yAxis2->setRange( -1, pTourData->getSession().maxSpeed * 3.6 * 1.05 );
        break;
    case DeviceBattery:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourBatterySoc() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourBatterySoc() );
        yAxis2->setRange( 0, 100 );
        break;
    case Cadence:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourCadence() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourCadence() );
        graph( Free2ndCurve )->setLineStyle( QCPGraph::lsNone );
        graph( Free2ndCurve )->setScatterStyle( QCPScatterStyle( QCPScatterStyle::ssCircle, 1 ) );
        graph( Free2ndCurve )->setPen( QColor( 0, 128, 255 ) );
        yAvg = { pTourData->getSession().avgCadence, pTourData->getSession().avgCadence };
        graph( AverageLine )->setData( xAvg, yAvg );
        yAxis2->setRange( -1, pTourData->getSession().maxCadence * 1.05 );
        break;
    case Temperature:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourTemperature() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourTemperature() );
        yAxis2->setRange( pTourData->getSession().minTemperature - 2, pTourData->getSession().maxTemperature + 2 );
        break;
    case Grade:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourGrade() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourGrade() );
        graph( Free2ndCurve )->setBrush( QBrush( QColor( 0, 180, 0, 25 ) ) );
        {double maxGrade = pTourData->getSession().maxGrade;
        if( maxGrade < -pTourData->getSession().minGrade ) maxGrade = -pTourData->getSession().minGrade;
        yAxis2->setRange( -maxGrade * 1.05, maxGrade * 1.05 );}
        break;
    case HeartRate:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourHeartRate() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourHeartRate() );
        yAvg = { pTourData->getSession().avgHeartRate, pTourData->getSession().avgHeartRate };
        graph( AverageLine )->setData( xAvg, yAvg );
        yAxis2->setRange( pTourData->getSession().minHeartRate - 5, pTourData->getSession().maxHeartRate + 5 );
        break;
    case Calories:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourCalories() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourCalories() );
        yAxis2->setRange( -1, pTourData->getSession().totalCalories * 1.05 );
        break;
    case Power:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourPower() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourPower() );
        yAvg = { pTourData->getSession().avgPower, pTourData->getSession().avgPower };
        graph( AverageLine )->setData( xAvg, yAvg );
        yAxis2->setRange( -1, pTourData->getSession().maxPower * 1.05 );
        break;
    case LRBalance:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourLRBalance() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourLRBalance() );
        graph(Free2ndCurve)->rescaleAxes();
        yAxis2->setRange( (int)((yAxis2->range().lower - 10)/20) * 20, (int)((yAxis2->range().upper + 10)/20) * 20 );
        break;
    case PedalSmoothness:
        if( xType == Distance )
        {
            graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourLPedalSmoothness() );
            graph( Free3rdCurve )->setData( pTourData->getTourDistance(), pTourData->getTourRPedalSmoothness() );
        }
        else
        {
            graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourLPedalSmoothness() );
            graph( Free3rdCurve )->setData( m_tourTimeStamp, pTourData->getTourRPedalSmoothness() );
        }
        graph(Free2ndCurve)->rescaleAxes();
        yAxis2->setRange( (int)((yAxis2->range().lower - 10)/20) * 20, (int)((yAxis2->range().upper + 10)/20) * 20 );
        break;
    case GearInfo:
        if( xType == Distance )
        {
            graph( Free2ndCurve )->setData( pTourData->getGearDistance(), pTourData->getGearRatio() );
            graph( Free3rdCurve )->setData( pTourData->getGearDistance(), pTourData->getGearNumFront() );
            graph( Free4thCurve )->setData( pTourData->getGearDistance(), pTourData->getGearNumRear() );
        }
        else
        {
            graph( Free2ndCurve )->setData( m_gearTimeStamp, pTourData->getGearRatio() );
            graph( Free3rdCurve )->setData( m_gearTimeStamp, pTourData->getGearNumFront() );
            graph( Free4thCurve )->setData( m_gearTimeStamp, pTourData->getGearNumRear() );
        }
        graph( Free2ndCurve )->setLineStyle( ( QCPGraph::lsStepRight ) );
        graph( Free3rdCurve )->setLineStyle( ( QCPGraph::lsStepRight ) );
        graph( Free4thCurve )->setLineStyle( ( QCPGraph::lsStepRight ) );
        //graph( Free2ndCurve )->rescaleAxes();
        //graph( Free3rdCurve )->rescaleAxes();
        graph( Free4thCurve )->rescaleAxes();
        //yAxis2->setRange( -0.1, pTourData->gearCountRear() + 1 );
        break;
    case GpsAccuracy:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourGpsAccuracy() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourGpsAccuracy() );
        graph(Free2ndCurve)->rescaleAxes();
        yAxis2->setRange( -1, yAxis2->range().upper * 1.05 );
        break;
    case WindSpeed:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourWindSpeed() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourWindSpeed() );
        graph( Free2ndCurve )->rescaleAxes();
        break;
    case AirSpeed:
        if( xType == Distance ) graph( Free2ndCurve )->setData( pTourData->getTourDistance(), pTourData->getTourAirSpeed() );
        else                    graph( Free2ndCurve )->setData( m_tourTimeStamp, pTourData->getTourAirSpeed() );
        graph( Free2ndCurve )->rescaleAxes();
        break;
    }

    //Lap lines with labels
    if( pTourData->getSections().count() > 1 )
    {
        for( int i = 0; i < pTourData->getSections().count(); i++ )
        {
            addGraph( xAxis, yAxis );
            graph( LapOneLine + i )->setPen( QPen( Qt::darkMagenta, m_lineWidth, Qt::DashDotLine ) );
            if( xType == Distance ) graph( LapOneLine + i )->setData( { pTourData->getSections().at( i ).startDistance, pTourData->getSections().at( i ).startDistance }, { -100, 8000 } );
            else                    graph( LapOneLine + i )->setData( { tourTimeToPlotTime( pTourData->getSections().at( i ).startTime ),
                                                                        tourTimeToPlotTime( pTourData->getSections().at( i ).startTime ) }, { -100, 8000 } );


            //Add the text label at the top
            QCPItemText *textLabel = new QCPItemText(this);
            textLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
            textLabel->position->setType(QCPItemPosition::ptPlotCoords);
            if( xType == Distance ) textLabel->position->setPixelPosition( QPointF( xAxis->coordToPixel( pTourData->getSections().at( i ).startDistance ), 0 ) );
            else                    textLabel->position->setPixelPosition( QPointF( xAxis->coordToPixel( tourTimeToPlotTime( pTourData->getSections().at( i ).startTime ) ), 0 ) );
            textLabel->setText( " " + QString::number( i + 1 ) );
            textLabel->setFont( QFont( font().family(), 10 ) );
            textLabel->setColor( Qt::darkMagenta );

            //Save for removal in future
            m_lapLabels.append(textLabel);
        }
    }
    m_xLimL = xAxis->range().lower;
    m_xLimU = xAxis->range().upper;
    m_y1LimL = yAxis->range().lower;
    m_y1LimU = yAxis->range().upper;
    m_y2LimL = yAxis2->range().lower;
    m_y2LimU = yAxis2->range().upper;
    replot();
    m_plotted = true;
}

void TourDataPlot::setAverageLineVisible( bool on )
{
    m_avgOn = on;
    graph( AverageLine )->setVisible( m_avgOn );
    replot();
}

double TourDataPlot::tourTimeToPlotTime( double time )
{
    QDateTime baseTime = QDateTime( QDate( 1989, 12, 31 ), QTime( 1, 0, 0 ) );
    QDateTime upTime = baseTime.addSecs( (int)time );
    return QCPAxisTickerDateTime::dateTimeToKey(upTime);
}

QVector<double> TourDataPlot::getTourTimeStamp() const
{
    return m_tourTimeStamp;
}

QVector<double> TourDataPlot::getGearTimeStamp() const
{
    return m_gearTimeStamp;
}

void TourDataPlot::mouseOverPlot(QMouseEvent *event)
{
    if( event->pos().x() > axisRect(0)->left()
     && event->pos().x() < axisRect(0)->right()
     && event->pos().y() > axisRect(0)->top()
     && event->pos().y() < axisRect(0)->bottom() )
    {
        double x = xAxis->pixelToCoord( event->pos().x() );
        QVector<double> xG = { x, x };
        QVector<double> yG = { -999999, 999999 };
        graph( TrackerLine )->setData( xG, yG );
        graph( TrackerLine )->setVisible( true );
        m_trackerLayer->replot();
    }
    else
    {
        graph( TrackerLine )->setVisible( false );
        m_trackerLayer->replot();
    }
}

void TourDataPlot::onXRangeChanged( QCPRange range )
{
    if( !m_plotted ) return;
    if( range.lower < m_xLimL )      xAxis->setRangeLower( m_xLimL );
    else if( range.upper > m_xLimU ) xAxis->setRangeUpper( m_xLimU );
}

void TourDataPlot::onY1RangeChanged( QCPRange range )
{
    if( !m_plotted ) return;
    if( range.lower < m_y1LimL )      yAxis->setRangeLower( m_y1LimL );
    else if( range.upper > m_y1LimU ) yAxis->setRangeUpper( m_y1LimU );
}

void TourDataPlot::onY2RangeChanged( QCPRange range )
{
    if( !m_plotted ) return;
    if( range.lower < m_y2LimL )      yAxis2->setRangeLower( m_y2LimL );
    else if( range.upper > m_y2LimU ) yAxis2->setRangeUpper( m_y2LimU );
}
