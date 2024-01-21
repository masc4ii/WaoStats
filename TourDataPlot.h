#ifndef TOURDATAPLOT_H
#define TOURDATAPLOT_H

#include "qcustomplot/qcustomplot.h"
#include "TourData.h"

enum ePlotXType{
    Distance = 0,
    Time
};

enum ePlotYType{
    Speed = 0,
    DeviceBattery,
    Cadence,
    Temperature,
    Grade,
    HeartRate,
    Calories,
    Power,
    LRBalance,
    GearInfo,
    GpsAccuracy
};

enum eGraph{
    AltitudeCurve = 0,
    Free2ndCurve,
    Free3rdCurve,
    Free4thCurve,
    AverageLine,
    TrackerLine,
    LapOneLine
};

class TourDataPlot : public QCustomPlot
{
    Q_OBJECT
public:
    TourDataPlot( QWidget *parent );
    void drawPlots( TourData *pTourData, ePlotXType xType, ePlotYType yType );
    void setAverageLineVisible( bool on );
    static double tourTimeToPlotTime( double time );

private slots:
    void mouseOverPlot( QMouseEvent *event );
    void onXRangeChanged( QCPRange range );
    void onY1RangeChanged( QCPRange range );
    void onY2RangeChanged( QCPRange range );

private:
    void init( void );
    ePlotXType m_xType{ Distance };
    ePlotYType m_yType{ Speed };
    bool m_avgOn{ false };
    QCPLayer* m_trackerLayer;
    QVector<QCPItemText*> m_lapLabels;
    double m_xLimU;
    double m_xLimL;
    double m_y1LimU;
    double m_y1LimL;
    double m_y2LimU;
    double m_y2LimL;
    bool m_plotted{false};
    const double m_graphWidth{1.0};
    const double m_lineWidth{1.05};
};

#endif // TOURDATAPLOT_H
