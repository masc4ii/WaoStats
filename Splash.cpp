#include "Splash.h"
#include "Globals.h"

#include <QLabel>
#include <QGridLayout>
#include <QString>

Splash::Splash(const QPixmap &pixmap, Qt::WindowFlags f) : QSplashScreen( pixmap, f )
{
    QGridLayout *pLayout = new QGridLayout( this );
    QLabel *pLabel1 = new QLabel( tr( "Loading..." ), this );
    QLabel *pLabel2 = new QLabel( QString( "v%1" ).arg( VERSION ), this );
    pLabel1->setAlignment( Qt::AlignLeft | Qt::AlignBottom );
    pLabel2->setAlignment( Qt::AlignRight | Qt::AlignBottom );
    pLayout->addWidget( pLabel1, 0, 0 );
    pLayout->addWidget( pLabel2, 0, 1 );
    pLayout->setMargin( 5 );
    setLayout( pLayout );
}
