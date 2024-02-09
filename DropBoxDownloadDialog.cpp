#include "DropBoxDownloadDialog.h"
#include "ui_DropBoxDownloadDialog.h"

#include <QMessageBox>
#include <QDir>
#include <QDirIterator>

#include "dropbox/DropboxClient.h"
#include "dropbox/files/FilesRoutes.h"
#include "dropbox/endpoint/DropboxAppInfo.h"
#include "dropbox/endpoint/DropboxAuthInfo.h"

using namespace dropboxQt;

DropBoxDownloadDialog::DropBoxDownloadDialog(QWidget *parent, QString token, QString workingPath) :
    QDialog(parent),
    ui(new Ui::DropBoxDownloadDialog),
    m_token(token),
    m_workingPath(workingPath)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint );
    ui->progressBar->setValue( 0 );

    setTitle( "Sync Dropbox" );
    setActionText( "tracks downloaded" );
}

DropBoxDownloadDialog::~DropBoxDownloadDialog()
{
    delete ui;
}

void DropBoxDownloadDialog::setActionText(QString text)
{
    m_actionText = text;
}

void DropBoxDownloadDialog::setTitle(QString text)
{
    setWindowTitle( text );
}

int DropBoxDownloadDialog::downloadResult()
{
    return m_NoneAccecptRejectError;
}

void DropBoxDownloadDialog::on_pushButtonAbort_clicked()
{
    m_NoneAccecptRejectError = 2;
    //reject();
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
    foreach( QString fitFile, m_downloadList )
    {
        QFile out( QString( m_workingPath + "New/" + fitFile ) );
        if(!out.open(QFile::WriteOnly|QIODevice::Truncate)){
            m_NoneAccecptRejectError = 3;
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
            QMessageBox::critical( this, tr( "Dropbox Exception" ), e.what() );
        }

        out.close();

        if( m_NoneAccecptRejectError == 2 )
        {
            reject();
            break;
        }
        todo--;
        ui->progressBar->setValue( 100 * ( (double)jobs - (double)todo ) / (double)jobs );
        ui->labelInfo->setText( QString( "%1 / %2 %3..." ).arg( jobs - todo ).arg( jobs ).arg( m_actionText ) );
        update();
    }
    accept();
    m_NoneAccecptRejectError = 1;
    return;
}
