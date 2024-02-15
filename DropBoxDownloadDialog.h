#pragma once

#include "ProgressDialog.h"
#include <QMutex>
#include <QTimerEvent>

class DropBoxDownloadDialog : public ProgressDialog
{
    Q_OBJECT

public:
    explicit DropBoxDownloadDialog(QWidget *parent = nullptr, QString token = QString(""), QString workingPath = QString(""));
    ~DropBoxDownloadDialog();
    bool createDownloadList( void );
    void downloadFiles( void );

private:
    int m_jobs;
    uint32_t *m_pTodo;
    QString m_token;
    QStringList m_downloadList;
    QString m_workingPath;
};
