#include "AdbWrapper.h"
#include <QProcess>
#include <QDebug>
#include <QApplication>

AdbWrapper::AdbWrapper(QObject *parent) :
    QObject(parent)
{
    m_adbProgram = QApplication::applicationDirPath() + "/adb";
}

void AdbWrapper::resetAdb()
{
    QStringList arguments;
    arguments << "kill-server";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(m_adbProgram, arguments);
    myProcess->waitForFinished();
    delete myProcess;

    arguments.clear();
    arguments << "start-server";
    myProcess = new QProcess(this);
    myProcess->start(m_adbProgram, arguments);
    myProcess->waitForFinished();
    delete myProcess;
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
        QString listStart = QString( "List of devices attached\r\n" );
        //qDebug() << res;
        QString listString = res.right( res.size() - listStart.size() - res.indexOf( listStart ) );
        //ui->textEdit->setText( listString );
        while( listString.right(1) == "\n" || listString.right(1) == "\r" ) listString.chop( 1 );

        if( !listString.isEmpty() ) deviceList = listString.split( "\r\n" );
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

    while( res.right(1) == "\n" || res.right(1) == "\r" ) res.chop( 1 );
    if( !res.isEmpty() )
    {
        if( res.indexOf( "\r\n" ) >= 0 ) trackList = res.split( "\r\n" );
        else trackList = res.split( "\n" );
    }
    //qDebug() << trackList.size() << trackList;

    return trackList;
}

bool AdbWrapper::downloadTrack(QString deviceId, QString name, QString dst)
{
    QStringList arguments;
    arguments<< "-s" << deviceId << "pull" << "/sdcard/exports/" + name << dst;
    //qDebug() << arguments;
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
