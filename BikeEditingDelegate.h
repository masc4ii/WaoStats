#ifndef BIKEEDITINGDELEGATE_H
#define BIKEEDITINGDELEGATE_H

#include <QTreeWidgetItem>
#include <QItemDelegate>
#include <QDropEvent>
#include <QDebug>
#include <QMimeData>

class BikeEditingDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    BikeEditingDelegate(QObject *parent = nullptr) : QItemDelegate(parent) {}
    virtual void setModelData(QWidget *editor,
                              QAbstractItemModel *model,
                              const QModelIndex &index) const
    {
        QItemDelegate::setModelData(editor, model, index);
        if (index.column() == 0) {
            emit editingFinished(index);
        }
    }

signals:
    void editingFinished(const QModelIndex &) const;
};

class BikeTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    BikeTreeWidget(QWidget *parent = nullptr) : QTreeWidget(parent)
    {
        auto rooItem = invisibleRootItem();
        rooItem->setFlags( rooItem->flags() ^ Qt::ItemIsDropEnabled );
    }
    QTreeWidgetItem *getItemFromIndex(const QModelIndex &index) const
    {
        return itemFromIndex(index);
    }
    QTreeWidgetItem * getDropTarget(QPoint pos)
    {
        QTreeWidgetItem *pItem = this->itemAt(pos);
        if (pItem)
        {
            // Prüfen, ob auf oder neben das Item gedropt wurde
            QRect rc = this->visualItemRect(pItem);
            QRect rcNew = QRect(rc.left(), rc.top() + 1, rc.width(), rc.height() - 2);
            if (rcNew.contains(pos, true))
            {
                //Wird unter das Item gedroppt? Dann sende parent.
                if( pItem->parent() ) pItem = pItem->parent();
            }
            else
                pItem = pItem->parent(); // Es wird NEBEN das Item gedropt -> Target ist das Parent-Item
        }

        return pItem;
    }
    void dragMoveEvent(QDragMoveEvent *event)
    {
        if (!getDropTarget(event->pos()))
        {
            // getDropTarget hat NULL zurückgeliefert -> Hier darf nicht gedropt werden
            event->ignore();
            return;
        }

        QTreeWidget::dragMoveEvent(event);
    }

    void dropEvent(QDropEvent *event)
    {
        QTreeWidgetItem *pItem = getDropTarget(event->pos());
        if (pItem)
            emit itemsDropped(this->selectedItems(), pItem);

        QTreeWidget::dropEvent(event);
    }

signals:
    void itemsDropped(QList<QTreeWidgetItem *> pSource, QTreeWidgetItem* pTarget);
};

#endif // BIKEEDITINGDELEGATE_H
