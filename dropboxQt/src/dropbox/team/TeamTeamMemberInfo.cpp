/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamTeamMemberInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///TeamMemberInfo

TeamMemberInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void TeamMemberInfo::toJson(QJsonObject& js)const{

    js["profile"] = (QJsonObject)m_profile;
    m_role.toJson(js, "role");
}

void TeamMemberInfo::fromJson(const QJsonObject& js){

    m_profile.fromJson(js["profile"].toObject());
    m_role.fromJson(js["role"].toObject());
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

}//team
}//dropboxQt
