#ifndef ADBDOWNLOADDIALOG_H
#define ADBDOWNLOADDIALOG_H

#include "ProgressDialog.h"

class AdbDownloadDialog : public ProgressDialog
{
    Q_OBJECT
public:
    AdbDownloadDialog(QWidget *parent = nullptr, QString deviceId = QString(""), QString workingPath = QString(""));
    ~AdbDownloadDialog();
    bool createDownloadList( void );
    void downloadFiles( void );

public slots:
    void downloadFile( void );

private:
    int m_jobs;
    int m_todo;
    QString m_deviceId;
    QStringList m_downloadList;
    QString m_workingPath;
};

#endif // ADBDOWNLOADDIALOG_H
