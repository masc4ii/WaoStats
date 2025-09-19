#include "CalendarWidget.h"

#include <QToolTip>
#include <QMap>
#include <QPainter>
#include <QModelIndex>
#include <QDebug>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QHeaderView>
#include <QMenu>
#include <QAction>

CalendarWidget::CalendarWidget(QWidget *parent)
    : QCalendarWidget(parent)
{
    setMouseTracking(true);
    installEventFilter(this);

    QTableView *tableView = findChild<QTableView*>();
    if (tableView) {
        tableView->setMouseTracking(true);
        tableView->installEventFilter(this);
    }
}

void CalendarWidget::setBikeDates(const QVector<QPair<QDateTime, QStringList>> &data)
{
    m_bikeDates.clear();
	m_originalData = data;
    
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
        painter->setCompositionMode(QPainter::CompositionMode_Multiply);
        QColor highlight = QBrush(this->palette().highlight()).color();
        highlight.setAlpha(128);
        painter->fillRect(rect.adjusted(1, 1, -1, -1), highlight);
        painter->restore();
    }
}

bool CalendarWidget::eventFilter(QObject *watched, QEvent *event)
{
    QTableView *tableView = findChild<QTableView*>();
    
    if (watched == tableView) {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            handleMouseMoveOnTable(mouseEvent, tableView);
        } else if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
			if (mouseEvent->button() == Qt::RightButton) {
                handleContextMenuOnTable(mouseEvent, tableView);
				return true;
            }
        } else if (event->type() == QEvent::ContextMenu) {
			QContextMenuEvent *contextEvent = static_cast<QContextMenuEvent*>(event);
            QMouseEvent fakeMouseEvent(QEvent::MouseButtonPress, 
                                     contextEvent->pos(), 
                                     Qt::RightButton, 
                                     Qt::RightButton, 
                                     contextEvent->modifiers());
            handleContextMenuOnTable(&fakeMouseEvent, tableView);
            return true;
        }
    }
    
    return QCalendarWidget::eventFilter(watched, event);
}

void CalendarWidget::handleMouseMoveOnTable(QMouseEvent *event, QTableView *tableView)
{
    QModelIndex index = tableView->indexAt(event->pos());
    
    if (index.isValid()) {
        QDate date = getDateFromModel(tableView, index);
        if (date.isValid() && m_bikeDates.contains(date)) {
            QString tooltipText = formatTooltipText(m_bikeDates[date]);
            QPoint globalPos = tableView->mapToGlobal(event->pos());
            QToolTip::showText(globalPos, tooltipText, this);
        } else {
            QToolTip::hideText();
        }
    } else {
        QToolTip::hideText();
    }
}

void CalendarWidget::handleContextMenuOnTable(QMouseEvent *event, QTableView *tableView)
{
    QModelIndex index = tableView->indexAt(event->pos());
    
    if (index.isValid()) {
        QDate date = getDateFromModel(tableView, index);
        if (date.isValid() && m_bikeDates.contains(date)) {
            m_contextMenuDate = date;
            
            QMenu contextMenu(this);
            
			// find all entries for this date
            QVector<QPair<QDateTime, QString>> entriesForDate;
            for (const auto &entry : m_originalData) {
                if (entry.first.date() == date) {
                    for (const QString &bikeName : entry.second) {
                        entriesForDate.append(qMakePair(entry.first, bikeName));
                    }
                }
            }
            
			// create actions for each entry
            for (int i = entriesForDate.size() - 1; i >= 0 ; i--) {
                const auto &entry = entriesForDate[i];
                QString actionText = QString("%1 (%2)").arg(entry.second, entry.first.time().toString("hh:mm"));
                
                QAction *action = contextMenu.addAction(actionText);
                action->setData(i); // Speichere den Index
                connect(action, &QAction::triggered, this, &CalendarWidget::onBikeActionTriggered);
            }
            
			// save entries for later use in slot
            m_contextMenuEntries = entriesForDate;
            
			// show context menu
            QPoint globalPos = tableView->mapToGlobal(event->pos());
            contextMenu.exec(globalPos);
        }
    }
}

void CalendarWidget::onBikeActionTriggered()
{
    QAction *action = qobject_cast<QAction*>(sender());
    if (action) {
        int index = action->data().toInt();
        if (index >= 0 && index < m_contextMenuEntries.size()) {
            const auto &entry = m_contextMenuEntries[index];
            emit bikeEntryClicked(entry.second, entry.first); // bikeName, dateTime
        }
    }
}

QString CalendarWidget::formatTooltipText(const QStringList &names) const
{
    QMap<QString, int> counts;

    for (const QString &name : names) {
        counts[name]++;
    }
    
    QStringList formattedList;
    for (auto it = counts.begin(); it != counts.end(); ++it) {
        const QString &name = it.key();
        int count = it.value();
        
        if (count == 1) {
            formattedList << name;
        } else {
            formattedList << QString("%1 (%2x)").arg(name).arg(count);
        }
    }
    
    return formattedList.join(", ");
}

QDate CalendarWidget::getDateFromModel(QTableView *tableView, const QModelIndex &index) const
{
    QAbstractItemModel *model = tableView->model();
    if (!model) {
        return QDate();
    }

	QVariant data = model->data(index, Qt::DisplayRole);
    QString dayStr = data.toString();
    bool ok;
    int day = dayStr.toInt(&ok);
    if (ok && day >= 1 && day <= 31) {
        int year = yearShown();
        int month = monthShown();
        int row = index.row();

        if (row == 0 && day > 15) {
            QDate prevMonth = QDate(year, month, 1).addMonths(-1);
            return QDate(prevMonth.year(), prevMonth.month(), day);
        } else if (row >= 4 && day <= 15) {
            QDate nextMonth = QDate(year, month, 1).addMonths(1);
            return QDate(nextMonth.year(), nextMonth.month(), day);
        } else {
            return QDate(year, month, day);
        }
    }
    
    return QDate();
}
