#ifndef SPLASH_H
#define SPLASH_H

#include <QSplashScreen>
#include <QPixmap>

class Splash : public QSplashScreen
{
    Q_OBJECT
public:
    Splash( const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = Qt::WindowFlags() );
};

#endif // SPLASH_H
