#pragma once
#include "ApiUtil.h"

namespace dropboxQt{
    class ApiClient: public QObject{
        Q_OBJECT
    public:
        ApiClient(){};
        ApiClient(const QString& access_token):m_token(access_token){};
        QString getToken()const{return m_token;}
        void setToken(QString s){m_token = s;}

    signals:
        void downloadProgress(qint64 bytesProcessed, qint64 total);
        void uploadProgress(qint64 bytesProcessed, qint64 total);

    protected:
        QString m_token;
    };
};
