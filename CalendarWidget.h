#pragma once

#include <QCalendarWidget>
#include <QMouseEvent>
#include <QDate>
#include <QStringList>
#include <QTableView>

class CalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = nullptr);
    void setBikeDates(const QVector<QPair<QDateTime, QStringList>> &data);

signals:
    void bikeEntryClicked(const QString &bikeName, const QDateTime &dateTime);

protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onBikeActionTriggered();

private:
    void handleMouseMoveOnTable(QMouseEvent *event, QTableView *tableView);
    void handleContextMenuOnTable(QMouseEvent *event, QTableView *tableView);
    QString formatTooltipText(const QStringList &names) const;
    QDate getDateFromModel(QTableView *tableView, const QModelIndex &index) const;
    
    QMap<QDate, QStringList> m_bikeDates;
	QVector<QPair<QDateTime, QStringList>> m_originalData;
    QDate m_contextMenuDate;
	QVector<QPair<QDateTime, QString>> m_contextMenuEntries; // Entries for current contextmenu
};
