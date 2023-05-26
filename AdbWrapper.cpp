#include "AdbWrapper.h"
#include <QProcess>
#include <QDebug>
#include <QApplication>

AdbWrapper::AdbWrapper(QObject *parent) :
    QObject(parent)
{
    m_adbProgram = QApplication::applicationDirPath() + "/adb";
}

QStringList AdbWrapper::deviceList()
{
    QStringList arguments;
    arguments << "devices" << "-l";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(m_adbProgram, arguments);

    QStringList deviceList;

    if( myProcess->waitForFinished() )
    {
        QString res = myProcess->readAll();
        res.chop( 1 ); //chop one \n
        QString listStart = QString( "List of devices attached\n" );
        //qDebug() << res;
        QString listString = res.right( res.size() - listStart.size() - res.indexOf( listStart ) );
        //ui->textEdit->setText( listString );

        if( !listString.isEmpty() ) deviceList = listString.split( "\n\n" );
        //qDebug() << deviceList << deviceList.size();
    }

    delete myProcess;
    return deviceList;
}

QStringList AdbWrapper::trackList(QString deviceId)
{
    QStringList trackList;

    QStringList arguments;
    arguments << "-s" << deviceId << "shell" << "ls" << "/sdcard/exports";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(m_adbProgram, arguments);

    if( !myProcess->waitForFinished() )
    {
        delete myProcess;
        return trackList;
    }

    QString res = myProcess->readAll();
    delete myProcess;

    res.chop( 1 ); //chop one \n
    if( !res.isEmpty() ) trackList = res.split( "\n" );
    //qDebug() << trackList.size() << trackList;

    return trackList;
}

bool AdbWrapper::downloadTrack(QString deviceId, QString name, QString dst)
{
    QStringList arguments;
    arguments<< "-s" << deviceId << "pull" << "/sdcard/exports/" + name << dst;
    QProcess *myProcess = new QProcess(this);
    myProcess->start(m_adbProgram, arguments);

    if( !myProcess->waitForFinished() )
    {
        delete myProcess;
        return false;
    }

    delete myProcess;
    return true;
}
