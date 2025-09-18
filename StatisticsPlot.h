#ifndef STATISTICSPLOT_H
#define STATISTICSPLOT_H

#include "qcustomplot/qcustomplot.h"

class StatisticsPlot : public QCustomPlot
{
    Q_OBJECT
public:
    StatisticsPlot( QWidget *parent );
    void init( void );
    void setDistanceLabel( void );
    void setAscentLabel( void );
    void setTimeMotionLabel( void );
    void setDayTicker( void );
    void setMonthTicker( void );
    void setYearTicker( void );
    void groupBars( QVector<QCPBars*> bikeBars );
    void stackBars( QVector<QCPBars*> bikeBars );
    void setLegendTitles( QVector<QCPBars*> bikeBars, QStringList names );
};

#endif // STATISTICSPLOT_H
