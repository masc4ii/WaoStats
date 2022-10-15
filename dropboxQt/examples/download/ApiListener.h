#pragma once

#include <QObject>

class ApiListener: public QObject
{
    Q_OBJECT

public slots:
    void progressDownload(qint64 bytesProcessed, qint64 total);
};
