#pragma once

#include <QCalendarWidget>
#include <QMouseEvent>
#include <QDate>
#include <QStringList>

class CalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = nullptr);

    void setBikeDates(const QVector<QPair<QDateTime, QStringList>> &data);

protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;

private:
    QMap<QDate, QStringList> m_bikeDates;
};

