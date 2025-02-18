#ifndef DROPBOXAUTHDIALOG_H
#define DROPBOXAUTHDIALOG_H

#include <QDialog>
#include "dropbox/endpoint/DropboxAppInfo.h"

using namespace dropboxQt;

namespace Ui {
class DropBoxAuthDialog;
}

class DropBoxAuthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DropBoxAuthDialog(QString workingPath, QWidget *parent = nullptr);
    ~DropBoxAuthDialog();
    QString getToken( void ){ return m_token; }

private slots:

    void on_pushButtonGetToken_clicked();
    void on_lineEditAuthCode_textChanged(const QString &arg1);
    void on_pushButtonPaste_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DropBoxAuthDialog *ui;
    QString m_url;
    DropboxAppInfo m_appInfo;
    QString m_token;
    QString m_workingPath;
};

#endif // DROPBOXAUTHDIALOG_H
