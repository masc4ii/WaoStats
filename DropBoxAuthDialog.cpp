#include "DropBoxAuthDialog.h"
#include "ui_DropBoxAuthDialog.h"

#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>
#include <QClipboard>

#include "dropbox/endpoint/DropboxWebAuth.h"
#include "dropbox/DropboxClient.h"

DropBoxAuthDialog::DropBoxAuthDialog(QString workingPath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DropBoxAuthDialog),
    m_workingPath(workingPath)
{
    ui->setupUi(this);
    if( m_appInfo.readFromFile( m_workingPath + "app.info" ) )
    {
        ui->lineEditAppKey->setText( m_appInfo.getKey() );
        ui->lineEditAppSecret->setText( m_appInfo.getSecret() );
    }
    ui->buttonBox->button( QDialogButtonBox::Ok )->setEnabled( false );
}

DropBoxAuthDialog::~DropBoxAuthDialog()
{
    delete ui;
}

void DropBoxAuthDialog::on_pushButtonGetToken_clicked()
{
    m_appInfo.setKeySecret( ui->lineEditAppKey->text(), ui->lineEditAppSecret->text() );
    m_appInfo.storeToFile( m_workingPath + "app.info" );
    m_url = DropboxWebAuth::getCodeAuthorizeUrl( m_appInfo );
    QDesktopServices::openUrl( QUrl( m_url ) );
    ui->lineEditAuthCode->setEnabled( true );
    ui->pushButtonPaste->setEnabled( true );
}

void DropBoxAuthDialog::on_lineEditAuthCode_textChanged(const QString &arg1)
{
    ui->buttonBox->button( QDialogButtonBox::Ok )->setEnabled( arg1.size() > 0 );
}

void DropBoxAuthDialog::on_pushButtonPaste_clicked()
{
    ui->lineEditAuthCode->setText( QGuiApplication::clipboard()->text() );
}

void DropBoxAuthDialog::on_buttonBox_accepted()
{
    try
    {
        DropboxAuthInfo authInfo = DropboxWebAuth::getTokenFromCode( m_appInfo, ui->lineEditAuthCode->text() );
        m_token = authInfo.getAccessToken();
        /*if( !authInfo.storeToFile( m_workingPath + "token.info" ) )
        {
            QMessageBox::critical( this, tr( "Dropbox Authentication" ), tr( "Error, failed to store access token to file." ) );
            reject();
            return;
        }*/
    }
    catch(DropboxException& e)
    {
        QMessageBox::critical( this, tr( "Dropbox Authentication" ), tr( "Exception: " ) + e.what() );
        reject();
        return;
    }
    accept();
    return;
}


void DropBoxAuthDialog::on_buttonBox_rejected()
{
    reject();
}

