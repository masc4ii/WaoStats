#include "VScrollArea.h"
#include <QScrollBar>

VScrollArea::VScrollArea(QWidget *parent) : QScrollArea( parent )
{
    this->horizontalScrollBar()->setEnabled( false );
}

void VScrollArea::resizeEvent(QResizeEvent *event)
{
    setMinimumWidth(widget()->minimumSizeHint().width() + verticalScrollBar()->width());
    QScrollArea::resizeEvent(event);
}
