#include "DropBoxDownloadDialog.h"
#include "ui_ProgressDialog.h"

#include <QDir>
#include <QDirIterator>

#include "dropbox/DropboxClient.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"

using namespace dropboxQt;

DropBoxDownloadDialog::DropBoxDownloadDialog(QWidget *parent, QString token, QString workingPath) :
    ProgressDialog(parent),
    m_token(token),
    m_workingPath(workingPath)
{
    setTitle( "Sync Dropbox..." );
    setActionText( tr( "tracks downloaded" ) );
}

DropBoxDownloadDialog::~DropBoxDownloadDialog()
{
}

bool DropBoxDownloadDialog::createDownloadList()
{
    //Load token
    DropboxClient c( m_token );

    //What are the new files?
    m_downloadList.clear();
    QDirIterator it( m_workingPath, QStringList() << "*.fit", QDir::Files, QDirIterator::Subdirectories);
    QStringList localList;
    while( it.hasNext() ) localList << QFileInfo( it.next() ).fileName();
    foreach( QString fitFile, c.listFolder( "/Apps/WahooFitness/" ) )
    {
        if( !localList.contains( fitFile ) ) m_downloadList << fitFile;
    }
    //qDebug() << downloadList;

    ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( 0 ).arg( m_downloadList.size() ).arg( m_actionText ) );

    return !m_downloadList.isEmpty();
}

void DropBoxDownloadDialog::downloadFiles()
{
    //Download all files
    DropboxClient c( m_token );
    int todo = m_downloadList.size();
    int jobs = todo;

    //Create Directory
    if( !QDir( m_workingPath + "New/" ).exists() )
        QDir().mkdir( m_workingPath + "New/" );

    foreach( QString fitFile, m_downloadList )
    {
        QFile out( QString( m_workingPath + "New/" + fitFile ) );
        if(!out.open(QFile::WriteOnly|QIODevice::Truncate)){
            m_retVal = RetError;
            close();
            return;
        }

        try
        {
            files::DownloadArg arg( QString( "/Apps/WahooFitness/" + fitFile ) );
            std::unique_ptr<files::Metadata> res = c.getFiles()->download(arg, &out);
        }
        catch(DropboxException& e)
        {
            m_retVal = RetError;
            return;
        }

        out.close();

        if( m_retVal == RetReject )
        {
            reject();
            return;
        }
        todo--;
        ui->progressBar->setValue( 100 * ( (double)jobs - (double)todo ) / (double)jobs );
        ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( jobs - todo ).arg( jobs ).arg( m_actionText ) );
        update();
    }
    accept();
    m_retVal = RetAccept;
    return;
}
