/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMemberLinkedApps.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MemberLinkedApps

MemberLinkedApps::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MemberLinkedApps::toJson(QJsonObject& js)const{

    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
    js["linked_api_apps"] = struct_list2jsonarray(m_linked_api_apps);
}

void MemberLinkedApps::fromJson(const QJsonObject& js){

    m_team_member_id = js["team_member_id"].toString();
    jsonarray2struct_list(js["linked_api_apps"].toArray(), m_linked_api_apps);
}

QString MemberLinkedApps::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MemberLinkedApps>  MemberLinkedApps::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MemberLinkedApps>  MemberLinkedApps::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MemberLinkedApps> rv;
    rv = std::unique_ptr<MemberLinkedApps>(new MemberLinkedApps);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
