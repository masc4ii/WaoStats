#include "StatisticsPlot.h"
#include <QToolTip>
#include <QMouseEvent>
#include <QDebug>
#include <limits>

StatisticsPlot::StatisticsPlot( QWidget *parent )
    : QCustomPlot( parent )
{
    init();
    replot();
}

void StatisticsPlot::init()
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

    // X Axis and grid
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

    QCPLayoutGrid *subLayout = new QCPLayoutGrid;
    plotLayout()->addElement(0, 1, subLayout);
    subLayout->addElement(0, 0, new QCPLayoutElement);
    subLayout->addElement(1, 0, legend);
    subLayout->addElement(2, 0, new QCPLayoutElement);
    plotLayout()->setColumnStretchFactor(1, 0.001);

    legend->setVisible(true);
    legend->setBorderPen( QColor( 0, 0, 0, 0 ) );
    legend->setBrush( QBrush( QColor( 0, 0, 0, 0 ) ) );
    legend->setMargins( QMargins( 0, 0, 0, 0 ) );
    legend->setFont( font );

    // Mouse-over tooltips
    connect(this, &QCustomPlot::mouseMove, this, [this](QMouseEvent *event){
        QPoint pos = event->pos();
        QCPAbstractPlottable *pl = plottableAt(pos);
        if (!pl) { QToolTip::hideText(); return; }
        QCPBars *bars = qobject_cast<QCPBars*>(pl);
        if (!bars) { QToolTip::hideText(); return; }

        // Get coordinate in plot coordinates (x)
        double xCoord = xAxis->pixelToCoord(pos.x());

        // Iterate bar data container, find nearest key
        auto dataMap = bars->data();
        if (!dataMap || dataMap->isEmpty()) { QToolTip::hideText(); return; }

        double bestDiff = std::numeric_limits<double>::infinity();
        double nearestKey = 0;
        double nearestValue = 0;
        for (auto it = dataMap->constBegin(); it != dataMap->constEnd(); ++it)
        {
            // In this qcustomplot version const_iterator is a pointer to QCPBarsData
            double key = it->key;
            double diff = qAbs(key - xCoord);
            if (diff < bestDiff)
            {
                bestDiff = diff;
                nearestKey = key;
                nearestValue = it->value;
            }
        }

        // Extract unit from y-axis label if present: "Label [unit]"
        QString unit;
        QString yLabel = yAxis->label();
        int l = yLabel.indexOf('[');
        int r = yLabel.indexOf(']');
        if (l != -1 && r > l) unit = yLabel.mid(l+1, r-l-1);
        unit = unit.trimmed();

        // Format the value
        QString valueStr;
        // Time case: unit "h" or label contains "Time" -> show as hhhh:mm
        if (!unit.isEmpty() && (unit == "h" || yLabel.contains("Time", Qt::CaseInsensitive)))
        {
            // nearestValue is in hours; round to nearest minute
            int totalMinutes = int(nearestValue * 60.0 + 0.5);
            int hours = totalMinutes / 60;
            int minutes = totalMinutes % 60;
            valueStr = QString("%1:%2").arg(hours).arg(minutes, 2, 10, QChar('0'));
        }
        // Ascent: no decimal places (unit "m" or label contains "Ascent")
        else if (!unit.isEmpty() && (unit == "m" || yLabel.contains("Ascent", Qt::CaseInsensitive)))
        {
            valueStr = QString::number(nearestValue, 'f', 0) + " " + unit;
        }
        // Distance: one decimal place (unit "km" or label contains "Distance")
        else if (!unit.isEmpty() && (unit == "km" || yLabel.contains("Distance", Qt::CaseInsensitive)))
        {
            valueStr = QString::number(nearestValue, 'f', 1) + " " + unit;
        }
        else if (!unit.isEmpty())
        {
            // Default: one decimal place
            valueStr = QString::number(nearestValue, 'f', 1) + " " + unit;
        }
        else
        {
            valueStr = QString::number(nearestValue, 'f', 1);
        }

        QString tooltip = QString("%1\n%2").arg(bars->name()).arg(valueStr);

        QToolTip::showText(event->globalPos(), tooltip, this);
    });
}

void StatisticsPlot::setDistanceLabel()
{
    yAxis->setLabel( tr( "Distance [km]" ) );
}

void StatisticsPlot::setAscentLabel()
{
    yAxis->setLabel( tr( "Ascent [m]" ) );
}

void StatisticsPlot::setTimeMotionLabel()
{
    yAxis->setLabel( tr( "Time Motion [h]" ) );
}

void StatisticsPlot::setDayTicker()
{
    QVector<double> vectorDays = QVector<double>() << 0 << 1 << 2 << 3 << 4 << 5 << 6;
    QVector<QString> labels = QVector<QString>() << tr( "Monday" ) << tr( "Tuesday" ) << tr( "Wednesday" ) << tr( "Thursday" ) << tr( "Friday" ) << tr( "Saturday" ) << tr( "Sunday" );
    QSharedPointer<QCPAxisTickerText> textTicker( new QCPAxisTickerText );
    textTicker->addTicks( vectorDays, labels );
    xAxis->setTicker( textTicker );
    xAxis->setRange( -0.5, 6.5 );
    xAxis->setLabel( tr( "Days of Week" ) );
}

void StatisticsPlot::setMonthTicker()
{
    QVector<double> vectorMonths = QVector<double>() << 0 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11;
    QVector<QString> labels = QVector<QString>() << tr( "January" ) << tr( "February" ) << tr( "March" ) << tr( "April" )
                                                 << tr( "May" ) << tr( "June" ) << tr( "Juli" ) << tr( "August" )
                                                 << tr( "September" ) << tr( "October" ) << tr( "November" ) << tr( "December" );
    QSharedPointer<QCPAxisTickerText> textTicker( new QCPAxisTickerText );
    textTicker->addTicks( vectorMonths, labels );
    xAxis->setTicker( textTicker );
    xAxis->setRange( -0.5, 11.5 );
    xAxis->setLabel( tr( "Month" ) );
}

void StatisticsPlot::setYearTicker()
{
    QSharedPointer<QCPAxisTicker> stdTicker( new QCPAxisTicker );
    xAxis->setTicker( stdTicker );
    xAxis->setLabel( tr( "Year" ) );
}

void StatisticsPlot::groupBars(QVector<QCPBars *> bikeBars)
{
    QCPBarsGroup *group = new QCPBarsGroup( this );
    foreach( QCPBars *bikeBar, bikeBars )
    {
        bikeBar->setBarsGroup(group);
        if( bikeBars.size() ) bikeBar->setWidth( 0.6 / bikeBars.size() );
    }
}

void StatisticsPlot::stackBars(QVector<QCPBars *> bikeBars)
{
    if( bikeBars.size() == 0 ) return;
    for( int i = 1; i < bikeBars.size(); i++ )
    {
        bikeBars.at(i)->setStackingGap(0);
        bikeBars.at(i)->moveAbove( bikeBars.at(i-1) );
        bikeBars.at(i)->setWidth( 0.7 );
    }
    bikeBars.at(0)->setWidth( 0.7 );
}

void StatisticsPlot::setLegendTitles(QVector<QCPBars *> bikeBars, QStringList names)
{
    if( bikeBars.size() != names.size() ) return;

    for( int i = 0; i < bikeBars.size(); i++ )
    {
        bikeBars.at(i)->setName( names.at(i) );
    }
}
