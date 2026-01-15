#pragma once

#include "qcustomplot/qcustomplot.h"

class PowerCurvePlot : public QCustomPlot
{
    Q_OBJECT
public:
    PowerCurvePlot( QWidget *parent );
    void init( void );
    void setData( QVector<QPair<double, double>> pwrCurve );
};

