#include "custompiechart.h"

#include <QDebug>

CustomPieChart::CustomPieChart(QWidget * parent)
    : QWidget (parent) {
    title = "Default Title"; // Title name
    total = 0;
    sumUnit = "";

    initPieChartWidget();
}

CustomPieChart::CustomPieChart(const QString &title, const QString &tag, const double &data,
                               const QColor &color, QWidget * parent)
    : QWidget (parent) {
    this->title = title; // Title name
    total = 1;           // Data length
    sum = data;          // Total data amount

    addSlice(tag,  data, color);
    initPieChartWidget();
}

CustomPieChart::CustomPieChart(const QString &title, QStringList tagList, QList<double> dataList,
                               QList<QColor> colorList, QWidget * parent)
    : QWidget (parent) {
    this->title = title; // Title name

    setSeries(tagList, dataList, colorList);
    initPieChartWidget();
}

CustomPieChart::~CustomPieChart() {}

/* Filter paint event */
bool CustomPieChart::eventFilter(QObject *widget, QEvent *event) {
    if (widget == pieChartWidget && event->type() == QEvent::Paint && total != 0) {
        drawPieChart(); // Draw the pie chart widget
    } else if (widget == titleWidget && event->type() == QEvent::Paint) {
        QPainter painter(titleWidget);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing); // Anti-aliasing for drawing and text
        painter.save();
        /* Draw the title widget */
        painter.setPen(Qt::white);

        titleFont.setPointSizeF(!isSetTitleFont ? titleWidget->height() * 0.75 : titleFont.pointSizeF());
        titleFont.setWeight(!isSetTitleFont ? QFont::Bold : titleFont.weight());
        painter.setFont(titleFont);
        painter.drawText(QRectF(0, 0, width(), height()), title);

        painter.restore();
    }
    return QWidget::eventFilter(widget, event);
}

/* Draw the pie chart */
void CustomPieChart::drawPieChart() {
    int width = this->width();
    int height = this->height();
    double min = qMin(width, height); // The smaller of width and height
    double diameter = min * 7 / 9;    // Diameter
    double radius = diameter / 2;     // Radius
    double startLength = 0;              // Starting length
    int midPoint = 0;                 // Coordinate origin
    double startAngle = 0;            // Starting angle

    QPainter painter(pieChartWidget);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing); // Anti-aliasing for drawing and text
    painter.translate(width / 2, height / 2);                                    // Shift starting point

    painter.save();

    fontSize = globalFont.pointSize();
    /* Draw total sum */
    sumFont.setPointSizeF(!isSetSumFont ? radius / 2.5 : sumFont.pointSizeF());
    painter.setFont(sumFont);
    //painter.setPen(QColor(54, 235, 171));
    painter.setPen(QColor(0, 0, 0));
    if( sumUnit == "hh:mm" )
    {
        int hours = (int)sum / 3600;
        int minutes = ((int)sum % 3600) / 60;

        QString sumString = QString( "%1:%2" ).arg( hours, 2, 10, QChar('0') ).arg( minutes, 2, 10, QChar('0') );

        painter.drawText(QRectF(-radius, -radius - (radius / 4), diameter, diameter),
                         Qt::AlignCenter, sumString + "\nhours:min");
    }
    else
    {
        painter.drawText(QRectF(-radius, -radius - (radius / 4), diameter, diameter),
                         Qt::AlignCenter, QString::number(sum, 'f', 2) + sumUnit);
    }
    /* Draw "Sum" text */
    //painter.setPen(Qt::white);
    sumTextFont.setPointSizeF(!isSetSumTextFont ? radius / 5 : sumTextFont.pointSizeF());
    painter.setFont(sumTextFont);
    painter.drawText(QRectF(-radius, -radius + fontSize, diameter, diameter), Qt::AlignCenter, "Sum");

    painter.setFont(globalFont);
    for (int count = 0; count < total; count++) {
        startLength += (count > 0)
                           ? (360 * 16 * dataList[count - 1] / sum) : 0;
        double arcLength = (360 * 16 * dataList[count] / sum); // Arc length
        double angle = 360 * dataList[count] / sum;            // Sector angle
        startAngle += (count > 0)
                          ? 360 * dataList[count - 1] / sum : 0;
        double radian = angle / 2 + startAngle; // Current radian (half-angle of the sector + sector start angle)
        double offset = fontSize;               // Offset
        double offsetX = 0;                     // X-axis offset
        double offsetY = 0;                     // Y-axis offset
        /* Draw sector area */
        painter.setPen(Qt::NoPen);
        QRadialGradient radialGradient(midPoint, midPoint, radius);
        radialGradient.setColorAt(0, Qt::transparent);
        radialGradient.setColorAt(ringSize, Qt::transparent);
        radialGradient.setColorAt((ringSize + 0.01 > 1) ? 1 : ringSize + 0.01,
                                  qFuzzyCompare(ringSize, 1)
                                      ? Qt::transparent : colorList[count]); // Set background color from color list
        radialGradient.setColorAt(1, qFuzzyCompare(ringSize, 1)
                                         ? Qt::transparent : colorList[count]);
        painter.setBrush(radialGradient);
        painter.drawPie(QRectF(-radius, -radius, diameter, diameter), startLength, arcLength); // Draw pie chart sector area
        /* Draw legend */
        painter.setPen(colorList[count]);
        painter.setBrush(colorList[count]);
        legendFont.setPointSizeF(!isSetLegendFont ? radius / 5 : legendFont.pointSizeF());
        painter.setFont(legendFont);
        fontSize = legendFont.pointSize();
        double totalHeight = total * fontSize * 1.3; // Berechne die Gesamthöhe der Legende
        double offsetYL = -totalHeight / 2; // Setze die y-Achse der Legende auf die Mitte
        painter.drawRect(QRectF(-(this->width() / 2) + 10, offsetYL + count * (fontSize * 1.3), fontSize / 2, fontSize / 2));
        painter.drawText(QRectF(-(this->width() / 2 - fontSize - 10), (offsetYL - fontSize / 3) + count * (fontSize * 1.3), 1000, radius), tagList[count]);

        /* Draw label polyline */
        tagFont.setPointSizeF(!isSetTagFont ? radius / 5 : tagFont.pointSizeF());
        painter.setFont(tagFont);
        fontSize = tagFont.pointSize();
        QPointF point = QPointF(midPoint + radius * cos(radian * M_PI / 180),
                                midPoint - radius * sin(radian * M_PI / 180)); // Quadrant point on the coordinate axis
        QPolygonF polygon; // Polyline
        polygon << point;
        QString tagText = QString::number(dataList[count] / sum * 100, 'f', 0) + "%";
        double textWidth = tagText.size() / 2 * fontSize;
        if (dataList[count] != 0) { // Only draw polyline and labels if data is not zero
            if (radian > 0 && radian <= 90) {          // First quadrant
                offsetX += offset;
                offsetY -= offset;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetX += textWidth;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetX -= textWidth;
                offsetY -= (fontSize * 1.5);
            } else if (radian > 90 && radian <= 180) { // Second quadrant
                offsetX -= offset;
                offsetY -= offset;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetX -= textWidth;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetY -= (fontSize * 1.5);
            } else if (radian > 180 && radian <= 270) { // Third quadrant
                offsetX -= offset;
                offsetY += offset;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetX -= textWidth;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
            } else if (radian > 270 && radian <= 360) { // Fourth quadrant
                offsetX += offset;
                offsetY += offset;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetX += textWidth;
                polygon << QPointF(point.x() + offsetX, point.y() + offsetY);
                offsetX -= textWidth;
            }
            painter.drawPolyline(polygon);
            /* Draw label */
            painter.drawText(QRectF(point.x() + offsetX*1.5, point.y() + offsetY,
                                    diameter, diameter), QStringLiteral("%1").arg(tagText));
        }
    }
    painter.restore();
}

/* Initialize pie chart widget */
void CustomPieChart::initPieChartWidget() {
    isSetTitleFont = false;
    isSetTagFont = false;
    isSetLegendFont = false;
    isSetSumFont = false;
    isSetSumTextFont = false;
    setRingSize(0.6);
    /* Title widget */
    //titleWidget = new QWidget(this);
    //titleWidget->installEventFilter(this);
    /* Pie chart widget */
    pieChartWidget = new QWidget(this);
    pieChartWidget->installEventFilter(this);

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);
    vBoxLayout->setSpacing(0);
    vBoxLayout->setMargin(0);
    //vBoxLayout->addWidget(titleWidget, 1);
    vBoxLayout->addWidget(pieChartWidget, 9);
    setLayout(vBoxLayout);
}
/* Add slice */
void CustomPieChart::addSlice(const QString &tag, const double &data, const QColor &color) {
    tagList << tag;                                // Tag name list
    dataList << data;                              // Data list
    colorList << color;                            // Color list
    total = dataList.size();                       // Data list length
    sum += data;                                   // Total data
}
/* Set series */
void CustomPieChart::setSeries(QStringList tagList, QList<double> dataList, QList<QColor> colorList) {
    total = dataList.size();     // Data list length
    sum = 0;                     // Total data
    this->tagList = tagList;     // Tag name list
    this->dataList = dataList;   // Data list
    this->colorList = colorList; // Color list
    for (int count = 0; count < total; count++) {
        sum += dataList[count];
    }
}

void CustomPieChart::setTitle(const QString &title) {
    this->title = title;
}
/* Set global font */
void CustomPieChart::setGlobalFont(const QFont &font) {
    globalFont = font;
    titleFont = font;
    tagFont = font;
    legendFont = font;
    sumFont = font;
    sumTextFont = font;
    sumFont = font;
    isSetTitleFont = true;
    isSetTagFont = true;
    isSetLegendFont = true;
    isSetSumFont = true;
    isSetSumTextFont = true;
}
/* Set title font */
void CustomPieChart::setTitleFont(const QFont &font) {
    titleFont = font;
    isSetTitleFont = true;
}
/* Set tag font */
void CustomPieChart::setTagFont(const QFont &font) {
    tagFont = font;
    isSetTagFont = true;
}
/* Set legend font */
void CustomPieChart::setLegendFont(const QFont &font) {
    legendFont = font;
    isSetLegendFont = true;
}
/* Set sum font */
void CustomPieChart::setSumFont(const QFont &font) {
    sumFont = font;
    isSetSumFont = true;
}
/* Set "Sum" text font */
void CustomPieChart::setSumTextFont(const QFont &font) {
    sumTextFont = font;
    isSetSumTextFont = true;
}
/* Set the unit of the sum */
void CustomPieChart::setSumUnit(const QString &unit)
{
    sumUnit = unit;
}
/* Set ring size */
void CustomPieChart::setRingSize(const double &ringSize) {
    this->ringSize = (ringSize > 1) ? 1 : ringSize;
}
