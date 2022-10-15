/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingShareFolderLaunch.h"

namespace dropboxQt{

namespace sharing{
///ShareFolderLaunch

ShareFolderLaunch::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ShareFolderLaunch::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case LaunchResultBase_ASYNC_JOB_ID:{
            if(!name.isEmpty())
                js[name] = QString("async_job_id");
            if(!m_async_job_id.isEmpty())
                js["async_job_id"] = QString(m_async_job_id);
        }break;
        case ShareFolderLaunch_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = (QJsonObject)m_complete;
        }break;
    }//switch
}

void ShareFolderLaunch::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("async_job_id") == 0){
        m_tag = LaunchResultBase_ASYNC_JOB_ID;
        m_async_job_id = js["async_job_id"].toString();
    }
    if(s.compare("complete") == 0){
        m_tag = ShareFolderLaunch_COMPLETE;
        m_complete.fromJson(js["complete"].toObject());
    }
}

QString ShareFolderLaunch::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ShareFolderLaunch");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ShareFolderLaunch>  ShareFolderLaunch::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ShareFolderLaunch> rv = std::unique_ptr<ShareFolderLaunch>(new ShareFolderLaunch);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
