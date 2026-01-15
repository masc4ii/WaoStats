#include "PowerCurvePlot.h"
#include <cmath>

PowerCurvePlot::PowerCurvePlot(QWidget *parent)
    : QCustomPlot( parent )
{
    init();
    replot();
}

void PowerCurvePlot::init()
{
    setBackground( QBrush( QColor( 0, 0, 0, 0 ) ) );
    axisRect(0)->setBackground( QBrush( QColor( 255, 255, 255 ) ) );
    axisRect(0)->setMargins( QMargins( 0, 0, 0, 0 ) );
    xAxis->setPadding( 0 );
    xAxis2->setPadding( 0 );
    yAxis->setPadding( 0 );
    yAxis2->setPadding( 0 );

    // Font
    QFont font = xAxis->labelFont();
#ifdef __APPLE__
    font.setPointSize( 10 );
#endif
    // Darkmode font color
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
        legend->setTextColor( Qt::white );
        axisRect(0)->setBackground( QColor( 64, 64, 64 ) );
    }

    // X Axis and grid - logarithmic scale
    //xAxis->setScaleType( QCPAxis::stLogarithmic );
    xAxis->setLabelFont( font );
    xAxis->setTickLabelFont( font );
    xAxis->grid()->setSubGridVisible( false );
    xAxis->grid()->setPen( QPen( Qt::lightGray, 0, Qt::SolidLine ) );
    xAxis->setTickLength( 0, 8 );
    xAxis->setLabelPadding( 0 );
    xAxis->setTickLabelPadding( 0 );
    xAxis->setOffset( 2 );

    // Y Axis left and grid
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
}

void PowerCurvePlot::setData(QVector<QPair<double, double> > pwrCurve)
{
    clearPlottables();
    
    if( pwrCurve.empty() )
    {
        replot();
        return;
    }

    double minPower = 0.0;
    double maxPower = pwrCurve.at(0).second;
    
    for( int i = 0; i < pwrCurve.size(); i++ )
    {
        if( pwrCurve.at(i).second > maxPower )
            maxPower = pwrCurve.at(i).second;
    }
    
    // Add padding to power range
    double powerRange = maxPower - minPower;
    if( powerRange < 1 ) powerRange = 1;
    maxPower += powerRange * 0.1;
    
    // Create graph
    QCPGraph *graph = addGraph();
    graph->setPen( QPen( QColor( 255, 0, 0 ), 1 ) );
    graph->setBrush( QBrush( QColor( 255, 0, 0, 30 ) ) );
    
    // Add data points directly (no transformation needed)
    QVector<double> xData, yData, index;
    for( int i = 0; i < pwrCurve.size(); i++ )
    {
        xData.append( pwrCurve.at(i).first );
        yData.append( pwrCurve.at(i).second );
        index.append( i );
    }
    graph->setData( index, yData );
    
    // Set axis ranges
    xAxis->setRange( 0, pwrCurve.size() - 1 );
    yAxis->setRange( minPower, maxPower );
    
    // Set axis labels
    //xAxis->setLabel( tr( "Time" ) );
    yAxis->setLabel( tr( "Power (W)" ) );

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    xAxis->setTicker(textTicker);
    for( int i = 0; i < pwrCurve.size(); i++ )
    {
        QString interval;
        if( pwrCurve.at(i).first < 60 )
            interval = QString::number( pwrCurve.at(i).first ) + "\nsec";
        else if( pwrCurve.at(i).first < 3600 )
            interval = QString::number( pwrCurve.at(i).first / 60 ) + "\nmin";
        else
            interval = QString::number( pwrCurve.at(i).first / 3600 ) + "\nh";

        textTicker->addTick( index.at(i), interval );
    }
    
    replot();
}
