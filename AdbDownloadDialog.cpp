#include "AdbDownloadDialog.h"
#include "ui_ProgressDialog.h"
#include "AdbWrapper.h"

#include <QDir>
#include <QDirIterator>
#include <QTimer>

AdbDownloadDialog::AdbDownloadDialog(QWidget *parent, QString deviceId, QString workingPath) :
    ProgressDialog(parent),
    m_deviceId(deviceId),
    m_workingPath(workingPath)
{
    setTitle( "Sync ADB..." );
    setActionText( tr( "tracks downloaded" ) );
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

    ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( 0 ).arg( m_downloadList.size() ).arg( m_actionText ) );
    //ui->labelInfo->setText( "Please wait while downloading tracks..." );
    //ui->progressBar->setVisible( false );

    m_jobs = m_downloadList.size();
    m_todo = m_downloadList.size();

    return !m_downloadList.isEmpty();
}

void AdbDownloadDialog::downloadFiles()
{
    //Create Directory
    if( !QDir( m_workingPath + "New/" ).exists() )
        QDir().mkdir( m_workingPath + "New/" );

    QTimer::singleShot( 0, this, SLOT(downloadFile()) );
}

void AdbDownloadDialog::downloadFile()
{
    //Download all files
    AdbWrapper *adbWrap = new AdbWrapper( this );
    QString fitFile = m_downloadList.first();
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
        m_todo--;
        ui->progressBar->setValue( 100 * ( (double)m_jobs - (double)m_todo ) / (double)m_jobs );
        ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( m_jobs - m_todo ).arg( m_jobs ).arg( m_actionText ) );
        update();
    }
    delete adbWrap;
    m_downloadList.removeFirst();

    if(m_downloadList.empty())
    {
        accept();
        m_retVal = RetAccept;
        return;
    }
    QTimer::singleShot( 0, this, SLOT( downloadFile() ) );
}
