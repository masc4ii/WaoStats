/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersAddJobStatus.h"

namespace dropboxQt{

namespace team{
///MembersAddJobStatus

MembersAddJobStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersAddJobStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case MembersAddJobStatus_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = struct_list2jsonarray(m_complete);
        }break;
        case MembersAddJobStatus_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("failed");
            if(!m_failed.isEmpty())
                js["failed"] = QString(m_failed);
        }break;
    }//switch
}

void MembersAddJobStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = MembersAddJobStatus_COMPLETE;
        jsonarray2struct_list(js["complete"].toArray(), m_complete);
    }
    else if(s.compare("failed") == 0){
        m_tag = MembersAddJobStatus_FAILED;
        m_failed = js["failed"].toString();
    }
}

QString MembersAddJobStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersAddJobStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersAddJobStatus>  MembersAddJobStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersAddJobStatus> rv = std::unique_ptr<MembersAddJobStatus>(new MembersAddJobStatus);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
