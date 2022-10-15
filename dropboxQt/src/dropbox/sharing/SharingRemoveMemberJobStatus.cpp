/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRemoveMemberJobStatus.h"

namespace dropboxQt{

namespace sharing{
///RemoveMemberJobStatus

RemoveMemberJobStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RemoveMemberJobStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case RemoveMemberJobStatus_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = (QJsonObject)m_complete;
        }break;
        case RemoveMemberJobStatus_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("failed");
            m_failed.toJson(js, "failed");
        }break;
    }//switch
}

void RemoveMemberJobStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = RemoveMemberJobStatus_COMPLETE;
        m_complete.fromJson(js["complete"].toObject());
    }
    else if(s.compare("failed") == 0){
        m_tag = RemoveMemberJobStatus_FAILED;
        m_failed.fromJson(js["failed"].toObject());
    }
}

QString RemoveMemberJobStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RemoveMemberJobStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RemoveMemberJobStatus>  RemoveMemberJobStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RemoveMemberJobStatus> rv = std::unique_ptr<RemoveMemberJobStatus>(new RemoveMemberJobStatus);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
