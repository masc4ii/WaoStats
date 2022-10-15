/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamTeamMemberStatus.h"

namespace dropboxQt{

namespace team{
///TeamMemberStatus

TeamMemberStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void TeamMemberStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case TeamMemberStatus_ACTIVE:{
            if(!name.isEmpty())
                js[name] = QString("active");
        }break;
        case TeamMemberStatus_INVITED:{
            if(!name.isEmpty())
                js[name] = QString("invited");
        }break;
        case TeamMemberStatus_SUSPENDED:{
            if(!name.isEmpty())
                js[name] = QString("suspended");
        }break;
        case TeamMemberStatus_REMOVED:{
            if(!name.isEmpty())
                js[name] = QString("removed");
            js["removed"] = (QJsonObject)m_removed;
        }break;
    }//switch
}

void TeamMemberStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("active") == 0){
        m_tag = TeamMemberStatus_ACTIVE;

    }
    else if(s.compare("invited") == 0){
        m_tag = TeamMemberStatus_INVITED;

    }
    else if(s.compare("suspended") == 0){
        m_tag = TeamMemberStatus_SUSPENDED;

    }
    else if(s.compare("removed") == 0){
        m_tag = TeamMemberStatus_REMOVED;
        m_removed.fromJson(js["removed"].toObject());
    }
}

QString TeamMemberStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "TeamMemberStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<TeamMemberStatus>  TeamMemberStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<TeamMemberStatus> rv = std::unique_ptr<TeamMemberStatus>(new TeamMemberStatus);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
