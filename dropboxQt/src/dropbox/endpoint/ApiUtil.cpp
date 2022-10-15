#include <QFile>
#include <QJsonParseError>
#include "ApiUtil.h"
#include "ApiEndpoint.h"

namespace dropboxQt{

    bool loadJsonFromFile(QString path, QJsonObject& js)
    {
        QFile jf(path);
        if(!jf.open(QFile::ReadOnly)){
            return false;
        }
        QJsonParseError  err;
        QJsonDocument jd = QJsonDocument().fromJson(jf.readAll(), &err);
        if(err.error == QJsonParseError::NoError){
            js = jd.object();
            return true;
        }
        return false;
    };

    bool storeJsonToFile(QString path, const QJsonObject js)
    {
        QFile jf(path);
        if(!jf.open(QFile::WriteOnly)){
            return false;
        }

        QJsonDocument jd(js);
        jf.write(jd.toJson());
        jf.close();
        return true;
    };


    VoidType& VoidType::instance()
    {
        static VoidType void_type;
        return void_type;
    };

    VoidType::operator QJsonObject ()const
    {
        static QJsonObject js;
        return js;
    };

    ///DropboxBaseTask
    bool DropboxBaseTask::waitForResult()const
    {
        if (!isCompleted() && !isFailed())
        {
            m_in_wait_loop = true;
            m_endpoint.runEventsLoop();
        }

        return isCompleted();
    };

    void DropboxBaseTask::notifyOnFinished()
    {
        emit finished();
        if (m_in_wait_loop)
        {
            m_endpoint.exitEventsLoop();
        }
    };

    void DropboxBaseTask::waitUntillFinishedOrCancelled()
    {
        m_endpoint.runEventsLoop();
    };
    
    void DropboxVoidTask::waitForResultAndRelease()
    {
        if (!isCompleted() && !isFailed())
        {
            m_in_wait_loop = true;
            m_endpoint.runEventsLoop();
        }

        if (isFailed())
        {
            std::unique_ptr<DropboxException> ex;
            ex = std::move(m_failed);
            deleteLater();
            if (ex)
                ex->raise();
        }
        deleteLater();
    };

}
