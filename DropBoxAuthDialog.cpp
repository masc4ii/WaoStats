#include "DropBoxAuthDialog.h"
#include "ui_DropBoxAuthDialog.h"

#include <QDebug>
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>

DropBoxAuthDialog::DropBoxAuthDialog(QString workingPath, QWidget *parent) :
    QDialog(parent),
    m_workingPath(workingPath),
    ui(new Ui::DropBoxAuthDialog)
{
    ui->setupUi(this);
    if( m_appInfo.readFromFile( m_workingPath + "app.info" ) )
    {
        ui->lineEditAppKey->setText( m_appInfo.getKey() );
        ui->lineEditAppSecret->setText( m_appInfo.getSecret() );
    }
}

DropBoxAuthDialog::~DropBoxAuthDialog()
{
    delete ui;
}

void DropBoxAuthDialog::on_pushButtonGetToken_clicked()
{
    m_appInfo.setKeySecret( ui->lineEditAppKey->text(), ui->lineEditAppSecret->text() );
    m_url = DropboxWebAuth::getCodeAuthorizeUrl( m_appInfo );
    QDesktopServices::openUrl( QUrl( m_url ) );
    ui->lineEditAuthCode->setEnabled( true );
}

void DropBoxAuthDialog::on_lineEditAuthCode_textChanged(const QString &arg1)
{
    ui->pushButtonOk->setEnabled( arg1.size() > 0 );
}

void DropBoxAuthDialog::on_pushButtonOk_clicked()
{
    try
    {
        DropboxAuthInfo authInfo = DropboxWebAuth::getTokenFromCode( m_appInfo, ui->lineEditAuthCode->text() );
        m_token = authInfo.getAccessToken();
        /*if( !authInfo.storeToFile( m_workingPath + "token.info" ) )
        {
            QMessageBox::critical( this, tr( "DropBox Authentication" ), tr( "Error, failed to store access token to file." ) );
            reject();
            return;
        }*/
    }
    catch(DropboxException& e)
    {
        QMessageBox::critical( this, tr( "DropBox Authentication" ), tr( "Exception: " ) + e.what() );
        reject();
        return;
    }
    accept();
    return;
}

