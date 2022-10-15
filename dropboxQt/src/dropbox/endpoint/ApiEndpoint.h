#pragma once

#include <set>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonObject>
#include <QEventLoop>
#include "ApiException.h"
#include "ApiClient.h"

namespace dropboxQt{
    class ApiEndpoint
    {      
        typedef std::set<QNetworkReply*> NET_REPLIES_IN_PROGRESS;

    public:
        ApiEndpoint(ApiClient* c);
        QString       lastRequestInfo()const{return m_last_request_info;}
        void          cancelAll();
        void          runEventsLoop()const;
        void          exitEventsLoop()const;

    protected:
        virtual void addAuthHeader(QNetworkRequest& request);
        
        virtual QNetworkReply*  getData(const QNetworkRequest &request);
        virtual QNetworkReply*  postData(const QNetworkRequest &request, const QByteArray& data);
        virtual QNetworkReply*  putData(const QNetworkRequest &request, const QByteArray& data);
        virtual QNetworkReply*  deleteData(const QNetworkRequest &request);

        virtual void            registerReply(QNetworkReply*);
        virtual void            unregisterReply(QNetworkReply*);
    protected:
        QNetworkAccessManager m_con_mgr;
        mutable QEventLoop    m_loop;
        ApiClient*            m_client;
        NET_REPLIES_IN_PROGRESS m_replies_in_progress;
        QString               m_last_request_info;        
    };
}
