/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingShareFolderJobStatus.h"

namespace dropboxQt{

namespace sharing{
///ShareFolderJobStatus

ShareFolderJobStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ShareFolderJobStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case ShareFolderJobStatus_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = (QJsonObject)m_complete;
        }break;
        case ShareFolderJobStatus_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("failed");
            m_failed.toJson(js, "failed");
        }break;
    }//switch
}

void ShareFolderJobStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = ShareFolderJobStatus_COMPLETE;
        m_complete.fromJson(js["complete"].toObject());
    }
    else if(s.compare("failed") == 0){
        m_tag = ShareFolderJobStatus_FAILED;
        m_failed.fromJson(js["failed"].toObject());
    }
}

QString ShareFolderJobStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ShareFolderJobStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ShareFolderJobStatus>  ShareFolderJobStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ShareFolderJobStatus> rv = std::unique_ptr<ShareFolderJobStatus>(new ShareFolderJobStatus);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
