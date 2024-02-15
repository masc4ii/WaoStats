#pragma once

#include <QDialog>
#include <QMutex>
#include <QTimerEvent>

namespace Ui {
class DropBoxDownloadDialog;
}

class DropBoxDownloadDialog : public QDialog
{
    Q_OBJECT

public:
    enum eDropBoxReturn {
        RetNone = 0,
        RetAccept,
        RetReject,
        RetError
    };
    explicit DropBoxDownloadDialog(QWidget *parent = nullptr, QString token = QString(""), QString workingPath = QString(""));
    ~DropBoxDownloadDialog();
    void setActionText( QString text );
    void setTitle( QString text );
    eDropBoxReturn downloadResult( void );
    bool createDownloadList( void );
    void downloadFiles( void );

private slots:
    void on_pushButtonAbort_clicked();

private:
    Ui::DropBoxDownloadDialog *ui;
    int m_jobs;
    QMutex *m_pMutex;
    uint32_t *m_pTodo;
    int m_timerId;
    QString m_actionText = QString( "tracks analyzed" );
    eDropBoxReturn m_retVal = RetNone;
    QString m_token;
    QStringList m_downloadList;
    QString m_workingPath;
};
