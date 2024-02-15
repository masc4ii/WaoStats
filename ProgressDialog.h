#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    enum eProgressReturn {
        RetNone = 0,
        RetAccept,
        RetReject,
        RetError
    };

    explicit ProgressDialog(QWidget *parent = nullptr);
    ~ProgressDialog();
    void setActionText( QString text );
    void setTitle( QString text );
    eProgressReturn downloadResult( void );

private slots:
    void on_pushButtonAbort_clicked();

protected:
    eProgressReturn m_retVal = RetNone;
    Ui::ProgressDialog *ui;
    QString m_actionText = QString( "" );
};

#endif // PROGRESSDIALOG_H
