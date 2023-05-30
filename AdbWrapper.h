#ifndef ADBWRAPPER_H
#define ADBWRAPPER_H

#include <QObject>
#include <QString>
#include <QStringList>

class AdbWrapper : public QObject
{
    Q_OBJECT
public:
    AdbWrapper(QObject *parent = nullptr);
    void resetAdb( void );
    QStringList deviceList( void );
    QStringList trackList( QString deviceId );
    bool downloadTrack(QString deviceId, QString src, QString dst );

protected:
    QString m_adbProgram;
};

#endif // ADBWRAPPER_H
