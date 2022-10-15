/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingTeamMemberInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///TeamMemberInfo

TeamMemberInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void TeamMemberInfo::toJson(QJsonObject& js)const{

    js["team_info"] = (QJsonObject)m_team_info;
    if(!m_display_name.isEmpty())
        js["display_name"] = QString(m_display_name);
    if(!m_member_id.isEmpty())
        js["member_id"] = QString(m_member_id);
}

void TeamMemberInfo::fromJson(const QJsonObject& js){

    m_team_info.fromJson(js["team_info"].toObject());
    m_display_name = js["display_name"].toString();
    m_member_id = js["member_id"].toString();
}

QString TeamMemberInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<TeamMemberInfo>  TeamMemberInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<TeamMemberInfo>  TeamMemberInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<TeamMemberInfo> rv;
    rv = std::unique_ptr<TeamMemberInfo>(new TeamMemberInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
