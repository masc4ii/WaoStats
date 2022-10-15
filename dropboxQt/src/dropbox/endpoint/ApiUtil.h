#pragma once

#include <list>
#include <memory>
#include <functional>
#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QVariant>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkReply>
#include "ApiException.h"

namespace dropboxQt {
    bool loadJsonFromFile(QString path, QJsonObject& js);
    bool storeJsonToFile(QString path, const QJsonObject js);

    template<class T>
    QJsonArray struct_list2jsonarray(const std::list<T>& lst)
    {
        QJsonArray rv;
        for (typename std::list<T>::const_iterator i = lst.cbegin(); i != lst.end(); i++) {
            T o = *i;
            QJsonObject js(o);
            rv.append(js);
        }
        return rv;
    };

    template<class T>
    QJsonArray struct_list2jsonarray_uptr(const std::list<std::unique_ptr<T>>& lst)
    {
        QJsonArray rv;
        for (typename std::list<std::unique_ptr<T>>::const_iterator i = lst.cbegin(); i != lst.end(); i++) {
            const std::unique_ptr<T>& o = *i;
            QJsonObject js;
            o->toJson(js);
            rv.append(js);
        }
        return rv;
    };


    template<class T>
    QJsonArray list_of_struct_list2jsonarray(const std::list <std::list<T>> & lst)
    {
        QJsonArray rv;
        for (typename std::list <std::list<T> >::const_iterator i = lst.cbegin(); i != lst.end(); i++) {
            const std::list<T>& IL = *i;
            QJsonArray arr2 = struct_list2jsonarray(IL);
            rv.append(arr2);
        }
        return rv;
    };

    template<class T>
    QJsonArray ingrl_list2jsonarray(const std::list<T>& lst)
    {
        QJsonArray rv;
        for (typename std::list<T>::const_iterator i = lst.cbegin(); i != lst.end(); i++) {
            const T o = *i;
            rv.append(o);
        }
        return rv;
    };

    template<class T>
    void jsonarray2struct_list(QJsonArray ar, std::list<T>& lst)
    {
        int Max = ar.size();
        for (int i = 0; i < Max; ++i) {
            QJsonObject js = ar[i].toObject();
            T o;
            o.fromJson(js);
            lst.push_back(o);
        }
    };

    template<class T>
    void jsonarray2struct_list_uptr(QJsonArray ar, std::list<std::unique_ptr<T>>& lst)
    {
        int Max = ar.size();
        for (int i = 0; i < Max; ++i) {
            QJsonObject js = ar[i].toObject();
            std::unique_ptr<T> o = T::factory::create(js);
            o->fromJson(js);
            lst.emplace_back(std::move(o));
        }
    };


    template<class T>
    void jsonarray2list(QJsonArray arr, std::list<T>& lst, std::true_type)
    {
# if QT_VERSION > QT_VERSION_CHECK(5, 6, 0)
        int Max = arr.size();
        for (int i = 0; i < Max; ++i) {
            auto v = arr[i].toInt();
            lst.push_back(v);
        }
#else
        int Max = arr.size();
        for (int i = 0; i < Max; ++i) {
            QString tmp = arr[i].toString();
            lst.push_back(tmp.toInt());
        }

#endif
    };

    template<class T>
    void jsonarray2list(const QJsonArray& arr, std::list<T>& lst, std::false_type)
    {
        int Max = arr.size();
        for (int i = 0; i < Max; ++i) {
            T v = arr[i].toString();
            lst.push_back(v);
        }
    };

    template<class T>
    void jsonarray2ingrl_list(const QJsonArray& arr, std::list<T >& lst)
    {
        jsonarray2list(arr, lst, std::is_integral<T>());
    };


    template<class T>
    void jsonarray2list_of_struct_list(QJsonArray arr, std::list <std::list<T>>& lst)
    {
        int Max = arr.size();
        for (int i = 0; i < Max; ++i) {
            QJsonArray arr2 = arr[i].toArray();
            std::list<T> lst2;
            jsonarray2struct_list(arr2, lst2);
            lst.push_back(lst2);
        }
    };

    class VoidType
    {
    public:
        static std::unique_ptr<VoidType> create(const QByteArray&)
        {
            return std::unique_ptr<VoidType>();
        };

        static VoidType& instance();
        operator QJsonObject ()const;
    };

    class NotAnException
    {
    public:
        static void raise(const QByteArray&, int, const std::string&) {};
    };

    template <class T, class D>
    class ListFromJsonLoader
    {
    public:
        static std::unique_ptr<T> create(const QByteArray& data)
        {
            std::unique_ptr<T> res(new T);
            QJsonDocument doc = QJsonDocument::fromJson(data);
            QJsonArray arr = doc.array();
            foreach(const QJsonValue & val, arr)
                {
                    QJsonObject js = val.toObject();
                    D o;
                    o.fromJson(js);
                    res->push_back(o);
                }
            return res;//std::move(res);
        }
    };


#define EXPECT(E, M) if(!E)qWarning() << M;
#define API_CHECK_STATE(E, M, S) if(!E){throw IllegalStateException(M, S); }

    class ApiEndpoint;
    
    class DropboxBaseTask : public QObject
    {
        Q_OBJECT;
        friend class Endpoint;
    public:
        virtual ~DropboxBaseTask() {};

        virtual bool isCompleted()const = 0;
        virtual bool isFailed()const { return (m_failed != nullptr); };

        DropboxException* error() 
        {
            DropboxException* rv = nullptr;
            if (m_failed)
                {
                    rv = m_failed.get();
                }
            return rv;
        };

        bool waitForResult()const;

    signals:
        void finished();

    protected:
        DropboxBaseTask(ApiEndpoint& ept):m_endpoint(ept){};

        void failed_callback(std::unique_ptr<DropboxException> ex) 
        {
            m_failed = std::move(ex);
            notifyOnFinished();
        };

        void notifyOnFinished();
        void waitUntillFinishedOrCancelled();
    protected:
        std::unique_ptr<DropboxException> m_failed;
        ApiEndpoint& m_endpoint;
        mutable bool m_in_wait_loop                 { false };
    };

    template <class RESULT>
    class DropboxTask : public DropboxBaseTask
    {
        friend class Endpoint;
    public:
        RESULT* get() 
        {
            RESULT* rv = nullptr;
            if (m_completed)
                {
                    rv = m_completed.get();
                }
            return rv;
        }

        virtual bool isCompleted()const override { return (m_completed != nullptr); };

        ///this function will block execution (via event loop) and return
        ///object in case os success or raise exception in case of error
        ///also this function will schedule dispose of the object via deleteLater
        std::unique_ptr<RESULT> waitForResultAndRelease()
        {
            std::unique_ptr<RESULT> res;
            if (!isCompleted() && !isFailed())
                {
                    m_in_wait_loop = true;
                    waitUntillFinishedOrCancelled();
                }
            
            if (isCompleted())
                {
                    res = std::move(m_completed);
                }
            else if (isFailed())
                {
                    std::unique_ptr<DropboxException> ex;
                    ex = std::move(m_failed);
                    deleteLater();
                    if (ex)
                        ex->raise();
                }
            deleteLater();
            return res;
        };

    protected:
        DropboxTask(ApiEndpoint& ept):DropboxBaseTask(ept){};
        void completed_callback(std::unique_ptr<RESULT> r) 
        {
            m_completed = std::move(r);
            notifyOnFinished();            
        };
    protected:
        std::unique_ptr<RESULT> m_completed;
    };

    class DropboxVoidTask : public DropboxBaseTask
    {
        friend class Endpoint;
    public:
        virtual bool isCompleted()const override { return m_completed; };

        ///this function will block execution (via event loop) and return
        ///object in case os success or raise exception in case of error
        ///also this function will schedule dispose of the object via deleteLater
        void waitForResultAndRelease();

    protected:
        DropboxVoidTask(ApiEndpoint& ept):DropboxBaseTask(ept) {};
        void completed_callback(void)
        {
            m_completed = true;
            notifyOnFinished();
        };

    protected:
        bool m_completed = {false};
    };

};
