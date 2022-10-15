#include <QUrl>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "DropboxWebAuth.h"
#include "DropboxAppInfo.h"
#include "DropboxHost.h"
#include "ApiException.h"

using namespace dropboxQt;

QString DropboxWebAuth::getCodeAuthorizeUrl(const DropboxAppInfo& appInfo, QString redirectUrl, QString antiCSRFstate)
{
    QUrl url(QString("https://%1/%2").arg(DropboxHost::DEFAULT().getWeb()).arg("oauth2/authorize"));
    QUrlQuery q;
    q.addQueryItem("response_type", "code");
    q.addQueryItem("client_id", appInfo.getKey());
    if(!redirectUrl.isEmpty()){
        q.addQueryItem("redirect_uri", redirectUrl);
    }
    if(!antiCSRFstate.isEmpty()){
        q.addQueryItem("state", antiCSRFstate);
    }
    url.setQuery(q);
    return url.toString();
};

DropboxAuthInfo DropboxWebAuth::getTokenFromCode(const DropboxAppInfo& appInfo, QString code)
{
    QNetworkAccessManager mgr;
    QEventLoop            loop;
    QUrl url(QString("https://%1/%2").arg(DropboxHost::DEFAULT().getApi()).arg("oauth2/token"));
    
    QUrlQuery q;
    q.addQueryItem("grant_type", "authorization_code");
    q.addQueryItem("code", code.toStdString().c_str());
    q.addQueryItem("client_id", appInfo.getKey().toStdString().c_str());
    q.addQueryItem("client_secret", appInfo.getSecret().toStdString().c_str());
    url.setQuery(q);

    QNetworkRequest req(url);
    req.setRawHeader("Content-Type", "application/x-www-form-urlencoded; charset=utf-8");

    bool ok = false;
    std::string errorInfo;
    int status_code = 0;    
    DropboxAuthInfo rv;
    QByteArray nothing2post;
    QNetworkReply *reply = mgr.post(req, nothing2post);
    QObject::connect(reply, &QNetworkReply::finished, [&]()
                     {
                         status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                         switch(status_code)
                             {
                             case 200:
                                 {
                                     QByteArray data = reply->readAll();
                                     if(!data.isEmpty())
                                         {
                                             QJsonDocument doc = QJsonDocument::fromJson(data);
                                             QJsonObject js_in = doc.object();
                                             rv.accessToken = js_in["access_token"].toString();
                                             ok = true;
                                         }              
                                 }break;
                             default:
                                 {
                                     QByteArray data = reply->readAll();
                                     QString tmp = QString("ERROR. Unexpected status %1").arg(status_code);
                                     tmp += data;
                                     errorInfo = tmp.toStdString();                
                                 }break;
                             }
                         reply->deleteLater();
                         loop.exit();
                         if(!ok)
                             {
                                 throw DropboxException(errorInfo, status_code, "");
                             }        
                     });
    loop.exec();

    return rv;
};

QString DropboxWebAuth::getCodeFromRedirectServer(QString httpsRedirectUrl, QString antiCSRFstate)
{
    QNetworkAccessManager mgr;
    QEventLoop            loop;

    QUrl url(httpsRedirectUrl); 
    QUrlQuery q;
    q.addQueryItem("state", antiCSRFstate.toStdString().c_str());
    url.setQuery(q);

    QNetworkRequest req(url);
    req.setRawHeader("Content-Type", "application/x-www-form-urlencoded; charset=utf-8");

    bool ok = false;
    std::string errorInfo;
    int status_code = 0;    
    QString rv;
    QByteArray nothing2post;
    QNetworkReply *reply = mgr.post(req, nothing2post);
    QObject::connect(reply, &QNetworkReply::finished, [&]()
                     {
                         status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                         switch(status_code)
                             {
                             case 200:
                                 {
                                     QByteArray data = reply->readAll();
                                     if(!data.isEmpty())
                                         {
                                             QJsonDocument doc = QJsonDocument::fromJson(data);
                                             QJsonObject js_in = doc.object();
                                             rv = js_in["code"].toString();
                                             ok = true;
                                         }              
                                 }break;
                             default:
                                 {
                                     QByteArray data = reply->readAll();
                                     QString tmp = QString("ERROR. Unexpected status %1").arg(status_code);
                                     tmp += data;
                                     errorInfo = tmp.toStdString();                
                                 }break;
                             }
                         reply->deleteLater();
                         loop.exit();
                         if(!ok)
                             {
                                 throw DropboxException(errorInfo, status_code, "");
                             }        
                     });
    loop.exec();
    return rv;
};
