#ifndef CUSTOMPIECHART_H
#define CUSTOMPIECHART_H

#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QtMath>

class CustomPieChart : public QWidget {
    Q_OBJECT

public:
    explicit CustomPieChart(QWidget * parent = nullptr);
    explicit CustomPieChart(const QString &title, const QString &tag, const double &data,
                            const QColor &color, QWidget * parent = nullptr);
    explicit CustomPieChart(const QString &title, QStringList tagList, QList<double> dataList,
                            QList<QColor> colorList, QWidget * parent = nullptr);
    ~CustomPieChart();
    void addSlice(const QString &tag, const double &data, const QColor &color);                                // Function to add a slice
    void setSeries(QStringList tagList, QList<double> value, QList<QColor> colorList); // Function to set the series
    void setTitle(const QString &title);                                                      // Function to set the title
    void setTitleFont(const QFont &font);                                                     // Function to set the title font
    void setTagFont(const QFont &font);                                                       // Function to set the tag font
    void setLegendFont(const QFont &font);                                                    // Function to set the legend font
    void setSumFont(const QFont &font);                                                       // Function to set the sum font
    void setSumTextFont(const QFont &font);                                                   // Function to set the "sum" text font
    void setSumUnit(const QString &unit);                                                     // Function to set the unit of the sum
    void setGlobalFont(const QFont &font);                                                    // Function to set the global font
    void setRingSize(const double &ringSize);                                                 // Function to set the ring size

private:
    int total;                                          // Total number of tags
    double sum;                                         // Total amount of tags
    QFont globalFont;                                   // Global font
    QFont titleFont;                                    // Title font
    QFont tagFont;                                      // Tag font
    QFont legendFont;                                   // Legend font
    QFont sumFont;                                      // Sum font
    QFont sumTextFont;                                  // "Sum" text font
    bool isSetTitleFont;                                // Whether the title font is set
    bool isSetTagFont;                                  // Whether the tag font is set
    bool isSetLegendFont;                               // Whether the legend font is set
    bool isSetSumFont;                                  // Whether the sum font is set
    bool isSetSumTextFont;                              // Whether the "sum" text font is set
    double fontSize;                                    // Font size
    double ringSize;                                    // Ring size
    QWidget * titleWidget;                              // Title widget
    QWidget * pieChartWidget;                           // Widget for drawing the pie chart
    QString title;                                      // Title name
    QString sumUnit;                                    // Unit of the sum
    QStringList tagList;                                // List of tags
    QList<double> dataList;                                // List of data
    QList<QColor> colorList;                            // List of colors
    bool eventFilter(QObject * widget, QEvent * event); // Function to filter drawing events
    void drawPieChart();                                // Function to draw the pie chart
    void initPieChartWidget();                          // Function to initialize the pie chart widget

};

#endif // CUSTOMPIECHART_H
