#pragma once

#include <functional>
#include "DropboxHost.h"
#include "ApiEndpoint.h"

namespace dropboxQt{

    class Endpoint : public ApiEndpoint {
    public:
        Endpoint(ApiClient* c);

        
        template <class ARG,
                  class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void rpcStyle(QString path, const ARG& arg, DropboxTask<RES>* t)
        {
            std::function<void(std::unique_ptr<RES>)> completed_callback =
                [=](std::unique_ptr<RES> r)
                {
                    t->completed_callback(std::move(r));
                };

            std::function<void(std::unique_ptr<DropboxException>)> failed_callback =
                [=](std::unique_ptr<DropboxException> ex) 
                {
                    t->failed_callback(std::move(ex));
                };

            rpcStyle<ARG, RES, RESULT_FACTORY, EXCEPTION>
                (path, arg, completed_callback, failed_callback);
        }   

        // void-arg + result
        template <class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void rpcStyle(QString path, DropboxTask<RES>* t)
        {
            rpcStyle<VoidType, RES, RESULT_FACTORY, EXCEPTION>
                (path, VoidType::instance(), t);
        }

        // void-arg + void-result
        template <class EXCEPTION>
        void rpcStyle(QString path, DropboxVoidTask* t)
        {
            rpcStyle<VoidType, EXCEPTION>(path, VoidType::instance(), t);
        }

        template <class ARG,
                  class EXCEPTION>
        void rpcStyle(QString path, const ARG& arg, DropboxVoidTask* t)
        {
            std::function<void(std::unique_ptr<dropboxQt::VoidType>)> completed_callback =
                [=](std::unique_ptr<dropboxQt::VoidType> )
                {
                    t->completed_callback();
                };

            std::function<void(std::unique_ptr<DropboxException>)> failed_callback =
                [=](std::unique_ptr<DropboxException> ex)
                {
                    t->failed_callback(std::move(ex));
                };

            rpcStyle<ARG, VoidType, VoidType, EXCEPTION>
                (path, arg, completed_callback, failed_callback);
        }


        template <class ARG,
                  class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void rpcStyle(QString path, const ARG& arg,
                      std::function<void(std::unique_ptr<RES>)> completed_callback = nullptr,
                      std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            RESULT_FACTORY factory;
            QByteArray bytes2post;
            QJsonObject js_out(arg);
            QUrl url(QString("https://%1/%2").arg(getHost().getApi()).arg(path));
            QNetworkRequest req(url);
            addAuthHeader(req);
            req.setRawHeader("Content-Type", "application/json; charset=utf-8");
            QJsonDocument doc(js_out);

            if (js_out.isEmpty()) {
                bytes2post.append("null");
            }
            else {
                QJsonDocument doc(js_out);
                bytes2post = doc.toJson(QJsonDocument::Compact);
            }
            QNetworkReply *reply = postData(req, bytes2post);           
            if (!reply)return;
            QObject::connect(reply, &QNetworkReply::finished, [=]()
                             {
                                 int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                                 switch (status_code)
                                     {
                                     case 200:
                                         {
                                             if (completed_callback != nullptr)
                                                 {
                                                     QByteArray data = reply->readAll();
                                                     completed_callback(factory.create(data));
                                                 }
                                         }break;

                                     case 409:
                                         {
                                             if (failed_callback != nullptr) {
                                                 QByteArray exception_data = reply->readAll();
                                                 std::string errorInfo = prepareErrorInfo(status_code,
                                                                                          url,
                                                                                          exception_data).toStdString();
                                                 failed_callback(EXCEPTION::create(exception_data,
                                                                                   status_code,
                                                                                   errorInfo));
                                             }
                                         }break;
                                     default:
                                         {
                                             if (failed_callback != nullptr) {
                                                 QByteArray exception_data = reply->readAll();
                                                 std::string errorInfo = prepareErrorInfo(status_code,
                                                                                          url,
                                                                                          exception_data).toStdString();
                                                 std::unique_ptr<DropboxException> ex(new DropboxException(errorInfo,
                                                                                                           status_code,
                                                                                                           ""));
                                                 failed_callback(std::move(ex));
                                             }
                                         }break;
                                     }
                                 unregisterReply(reply);
                             });//finished
        }

        // void-arg + result
        template <class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void rpcStyle(QString path,
                      std::function<void(std::unique_ptr<RES>)> completed_callback = nullptr,
                      std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            rpcStyle<VoidType, RES, RESULT_FACTORY, EXCEPTION>(path,
                                                               VoidType::instance(),
                                                               completed_callback,
                                                               failed_callback);
        }

        // arg + void-result
        template <class ARG,
                  class EXCEPTION>
        void rpcStyle(QString path,
                      const ARG& arg,
                      std::function<void()> completed_callback = nullptr,
                      std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            std::function<void(std::unique_ptr<dropboxQt::VoidType>)> completed_with_type = nullptr;
            if (completed_callback != nullptr)
                {
                    completed_with_type = [=](std::unique_ptr<dropboxQt::VoidType>)
                        {
                            completed_callback();
                        };
                }
            rpcStyle<ARG, VoidType, VoidType, EXCEPTION>(path,
                                                         arg,
                                                         completed_with_type,
                                                         failed_callback);
        }

        // void-arg + void-result
        template <class EXCEPTION>
        void rpcStyle(QString path,
                      std::function<void()> completed_callback = nullptr,
                      std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            std::function<void(std::unique_ptr<dropboxQt::VoidType>)> completed_with_type = nullptr;
            if (completed_callback != nullptr)
                {
                    completed_with_type = [=](std::unique_ptr<dropboxQt::VoidType>)
                        {
                            completed_callback();
                        };
                }

            rpcStyle<VoidType,
                     VoidType,
                     VoidType,
                     EXCEPTION>(path,
                                VoidType::instance(),
                                completed_with_type,
                                failed_callback);
        }

        template <class ARG,
                  class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void downloadStyle(QString path,
                           const ARG& arg,
                           QIODevice* writeTo,
                           DropboxTask<RES>* t)
        {
            std::function<void(std::unique_ptr<RES>)> completed_callback =
                [=](std::unique_ptr<RES> r)
                {
                    t->completed_callback(std::move(r));
                };

            std::function<void(std::unique_ptr<DropboxException>)> failed_callback =
                [=](std::unique_ptr<DropboxException> ex)
                {
                    t->failed_callback(std::move(ex));
                };

            downloadStyle<ARG, RES, RESULT_FACTORY, EXCEPTION>
                (path, arg, writeTo, completed_callback, failed_callback);
        }

        template <class ARG,
                  class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void downloadStyle(QString path,
                           const ARG& arg,
                           QIODevice* writeTo,
                           std::function<void(std::unique_ptr<RES>)> completed_callback = nullptr,
                           std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            QJsonObject js_out(arg);
            QUrl url(QString("https://%1/%2").arg(getHost().getContent()).arg(path));
            QNetworkRequest req(url);
            addAuthHeader(req);
            QJsonDocument doc(js_out);
            req.setRawHeader("Dropbox-API-Arg", doc.toJson(QJsonDocument::Compact));

            RESULT_FACTORY factory;
            QByteArray bytes2post;
            QNetworkReply *reply = postData(req, bytes2post);
            if (!reply)return;
            QObject::connect(reply, &QNetworkReply::readyRead, [=]()
                             {
                                 qint64 sz = reply->bytesAvailable();
                                 if (sz > 0 && writeTo != NULL) {
                                     QByteArray data = reply->read(sz);
                                     writeTo->write(data);
                                 }
                             });

            QObject::connect(reply, &QNetworkReply::finished, [=]()
                             {
                                 int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                                 switch (status_code)
                                     {
                                     case 200:
                                         {
                                             if (completed_callback != nullptr)
                                                 {
                                                     completed_callback(factory.create(QByteArray()));
                                                 }
                                         }break;// fall-through
                                     case 206:
                                         {
                                             if (completed_callback != nullptr)
                                                 {
                                                     bool processed206 = false;
                                                     QList<QByteArray> lst = reply->rawHeaderList();
                                                     for (QList<QByteArray>::iterator i = lst.begin(); i != lst.end(); i++) {
                                                         QByteArray data = reply->rawHeader(*i);
                                                         if (!data.isEmpty())
                                                             {
                                                                 processed206 = true;
                                                                 completed_callback(factory.create(data));
                                                                 break;
                                                             }
                                                     }

                                                     if(!processed206){
                                                         completed_callback(factory.create(QByteArray()));
                                                     }
                                                 }
                                         }break;
                                     default:
                                         {
                                             if (failed_callback != nullptr)
                                                 {
                                                     QByteArray exception_data = reply->readAll();
                                                     std::string errorInfo = prepareErrorInfo(status_code,
                                                                                              url,
                                                                                              exception_data).toStdString();
                                                     failed_callback(EXCEPTION::create(exception_data,
                                                                                       status_code,
                                                                                       errorInfo));
                                                 }
                                         }
                                     }
                                 unregisterReply(reply);
                             });//finished
        }

        template <class ARG,
                  class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void uploadStyle(QString path, 
                         const ARG& arg, 
                         QIODevice* readFrom,
                         DropboxTask<RES>* t)
        {
            std::function<void(std::unique_ptr<RES>)> completed_callback =
                [=](std::unique_ptr<RES> r)
                {
                    t->completed_callback(std::move(r));
                };

            std::function<void(std::unique_ptr<DropboxException>)> failed_callback =
                [=](std::unique_ptr<DropboxException> ex)
                {
                    t->failed_callback(std::move(ex));
                };

            uploadStyle<ARG, RES, RESULT_FACTORY, EXCEPTION>
                (path, arg, readFrom, completed_callback, failed_callback);
        }

        // arg + void-result
        template <class ARG,
                  class EXCEPTION>
        void uploadStyle(QString path,
                         const ARG& arg,
                         QIODevice* readFrom,
                         DropboxVoidTask* t)
        {           
            std::function<void(std::unique_ptr<dropboxQt::VoidType>)> completed_callback =
                [=](std::unique_ptr<dropboxQt::VoidType> )
                {
                    t->completed_callback();
                };

            std::function<void(std::unique_ptr<DropboxException>)> failed_callback =
                [=](std::unique_ptr<DropboxException> ex)
                {
                    t->failed_callback(std::move(ex));
                };

            uploadStyle<ARG, VoidType, VoidType, EXCEPTION>
                (path, arg, readFrom, completed_callback, failed_callback);
        }

        template <class ARG,
                  class RES,
                  class RESULT_FACTORY,
                  class EXCEPTION>
        void uploadStyle(QString path,
                         const ARG& arg,
                         QIODevice* readFrom,
                         std::function<void(std::unique_ptr<RES>)> completed_callback = nullptr,
                         std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            QJsonObject js_out(arg);
            QUrl url(QString("https://%1/%2").arg(getHost().getContent()).arg(path));
            QNetworkRequest req(url);
            addAuthHeader(req);
            QJsonDocument doc(js_out);
            req.setRawHeader("Dropbox-API-Arg", doc.toJson(QJsonDocument::Compact));
            req.setRawHeader("Content-Type", "application/octet-stream");

            RESULT_FACTORY factory;
            QNetworkReply *reply = postData(req, readFrom ? readFrom->readAll() : QByteArray());
            if (!reply)return;
            QObject::connect(reply, &QNetworkReply::finished, [=]()
                             {
                                 int status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
                                 switch (status_code)
                                     {
                                     case 200: {
                                         if (completed_callback != NULL)
                                             {
                                                 QByteArray data = reply->readAll();
                                                 completed_callback(factory.create(data));
                                             }
                                     }break;
                                     default:
                                         {
                                             if (failed_callback != nullptr)
                                                 {
                                                     QByteArray exception_data = reply->readAll();
                                                     std::string errorInfo = prepareErrorInfo(status_code,
                                                                                              url,
                                                                                              exception_data).toStdString();
                                                     failed_callback(EXCEPTION::create(exception_data,
                                                                                       status_code,
                                                                                       errorInfo));
                                                 }
                                         }
                                     }
                                 unregisterReply(reply);
                             });//finished
        }//uploadStyle

        // arg + void-result
        template <class ARG,
                  class EXCEPTION>
        void uploadStyle(QString path,
                         const ARG& arg,
                         QIODevice* readFrom,
                         std::function<void(void)> completed_callback = nullptr,
                         std::function<void(std::unique_ptr<DropboxException>)> failed_callback = nullptr)
        {
            std::function<void(std::unique_ptr<dropboxQt::VoidType>)> completed_with_type = nullptr;
            if (completed_callback != nullptr)
                {
                    completed_with_type = [=](std::unique_ptr<dropboxQt::VoidType>)
                        {
                            completed_callback();
                        };
                }
            uploadStyle<ARG, VoidType, VoidType, EXCEPTION>(path,
                                                            arg,
                                                            readFrom,
                                                            completed_with_type,
                                                            failed_callback);
        }

        const DropboxHost& getHost()const { return DropboxHost::DEFAULT(); }

        template <class T>
        DropboxTask<T>* produceTask() 
        {
            DropboxTask<T>* rv = new DropboxTask<T>(*this);
            return rv;
        };

        DropboxVoidTask* produceVoidTask() 
        {
            return new DropboxVoidTask(*this);          
        }

    protected:

        QString prepareErrorInfo(int status_code, const QUrl& url, const QByteArray& data);
    };//Endpoint
}//dropboxQt
