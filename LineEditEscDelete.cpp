#include "LineEditEscDelete.h"

LineEditEscDelete::LineEditEscDelete( QWidget *parent )
    : QLineEdit( parent )
{
}

void LineEditEscDelete::keyPressEvent( QKeyEvent *event )
{
    if( event->key() == Qt::Key_Escape )
    {
        this->clear();
    }
    QLineEdit::keyPressEvent( event );
}
