#ifndef VSCROLLAREA_H
#define VSCROLLAREA_H

#include <QScrollArea>
#include <QResizeEvent>

class VScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    VScrollArea( QWidget *parent = nullptr );
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // VSCROLLAREA_H
