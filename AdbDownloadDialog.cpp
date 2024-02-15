#include "AdbDownloadDialog.h"
#include "ui_ProgressDialog.h"
#include "AdbWrapper.h"

#include <QDir>
#include <QDirIterator>

AdbDownloadDialog::AdbDownloadDialog(QWidget *parent, QString deviceId, QString workingPath) :
    ProgressDialog(parent),
    m_deviceId(deviceId),
    m_workingPath(workingPath)
{
    setTitle( "Sync ADB..." );
    setActionText(QString( "tracks downloaded" ));
}

AdbDownloadDialog::~AdbDownloadDialog()
{
}

bool AdbDownloadDialog::createDownloadList()
{
    //Get all names of files from Wahoo device
    AdbWrapper *adbWrap = new AdbWrapper( this );
    QStringList trackList = adbWrap->trackList( m_deviceId );
    delete adbWrap;

    if( trackList.empty() )
    {
        return false;
    }

    //What are the new files?
    m_downloadList.clear();
    QDirIterator it( m_workingPath, QStringList() << "*.fit", QDir::Files, QDirIterator::Subdirectories);
    QStringList localList;
    while( it.hasNext() ) localList << QFileInfo( it.next() ).fileName();
    foreach( QString fitFile, trackList )
    {
        if( !localList.contains( fitFile ) ) m_downloadList << fitFile;
    }
    //qDebug() << downloadList;

    //ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( 0 ).arg( m_downloadList.size() ).arg( m_actionText ) );
    ui->labelInfo->setText( "Please wait while downloading tracks..." );
    ui->progressBar->setVisible( false );

    return !m_downloadList.isEmpty();
}

void AdbDownloadDialog::downloadFiles()
{
    int todo = m_downloadList.size();
    int jobs = todo;

    //Create Directory
    if( !QDir( m_workingPath + "New/" ).exists() )
        QDir().mkdir( m_workingPath + "New/" );

    //Download all files
    AdbWrapper *adbWrap = new AdbWrapper( this );
    foreach( QString fitFile, m_downloadList )
    {
        if( !adbWrap->downloadTrack( m_deviceId, fitFile, m_workingPath + "New/" ) )
        {
            m_retVal = RetError;
            return;
        }
        if( m_retVal == RetReject )
        {
            reject();
            return;
        }
        todo--;
        ui->progressBar->setValue( 100 * ( (double)m_jobs - (double)todo ) / (double)jobs );
        //ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( jobs - todo ).arg( jobs ).arg( m_actionText ) );
        update();
        repaint();
    }
    delete adbWrap;
    accept();
    m_retVal = RetAccept;
    return;
}
