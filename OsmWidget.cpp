#include "OsmWidget.h"

OsmWidget::OsmWidget(QWidget *parent)
    : QWidget{parent}
{

}

void OsmWidget::resizeEvent(QResizeEvent *)
{
    emit resized();
}
