#ifndef LINEEDITESCDELETE_H
#define LINEEDITESCDELETE_H

#include <QLineEdit>
#include <QKeyEvent>

class LineEditEscDelete : public QLineEdit
{
    Q_OBJECT
public:
    LineEditEscDelete( QWidget *parent );
    void keyPressEvent( QKeyEvent *event );
};

#endif // LINEEDITESCDELETE_H
