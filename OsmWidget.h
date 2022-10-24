#ifndef OSMWIDGET_H
#define OSMWIDGET_H

#include <QWidget>
#include <QResizeEvent>

class OsmWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OsmWidget(QWidget *parent = nullptr);

private:
    void resizeEvent( QResizeEvent *event );

signals:
    void resized( void );

};

#endif // OSMWIDGET_H
