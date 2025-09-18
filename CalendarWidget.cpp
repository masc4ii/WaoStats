#include "CalendarWidget.h"

#include <QToolTip>
#include <QMap>
#include <QPainter>
#include <QModelIndex>

CalendarWidget::CalendarWidget(QWidget *parent)
    : QCalendarWidget(parent)
{
    setMouseTracking(true);
}

void CalendarWidget::setBikeDates(const QVector<QPair<QDateTime, QStringList>> &data)
{
    m_bikeDates.clear();
    for (const auto &entry : data) {
        m_bikeDates[entry.first.date()] += entry.second;
    }
    updateCells();
}

void CalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    QCalendarWidget::paintCell(painter, rect, date);

    if (m_bikeDates.contains(date)) {
        painter->save();
        QColor highlight = QBrush(this->palette().highlight()).color();
        highlight.setAlpha(128);
        painter->fillRect(rect.adjusted(1, 1, -1, -1), highlight);
        painter->restore();
    }
}
