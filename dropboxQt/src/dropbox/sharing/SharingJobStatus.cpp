/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingJobStatus.h"

namespace dropboxQt{

namespace sharing{
///JobStatus

JobStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void JobStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case JobStatus_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
        }break;
        case JobStatus_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("failed");
            m_failed.toJson(js, "failed");
        }break;
    }//switch
}

void JobStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = JobStatus_COMPLETE;

    }
    else if(s.compare("failed") == 0){
        m_tag = JobStatus_FAILED;
        m_failed.fromJson(js["failed"].toObject());
    }
}

QString JobStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "JobStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<JobStatus>  JobStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<JobStatus> rv = std::unique_ptr<JobStatus>(new JobStatus);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
