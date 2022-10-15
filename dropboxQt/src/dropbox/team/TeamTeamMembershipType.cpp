/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamTeamMembershipType.h"

namespace dropboxQt{

namespace team{
///TeamMembershipType

TeamMembershipType::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void TeamMembershipType::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case TeamMembershipType_FULL:{
            if(!name.isEmpty())
                js[name] = QString("full");
        }break;
        case TeamMembershipType_LIMITED:{
            if(!name.isEmpty())
                js[name] = QString("limited");
        }break;
    }//switch
}

void TeamMembershipType::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("full") == 0){
        m_tag = TeamMembershipType_FULL;

    }
    else if(s.compare("limited") == 0){
        m_tag = TeamMembershipType_LIMITED;

    }
}

QString TeamMembershipType::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "TeamMembershipType");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<TeamMembershipType>  TeamMembershipType::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<TeamMembershipType> rv = std::unique_ptr<TeamMembershipType>(new TeamMembershipType);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
