/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team_policies/TeamPoliciesTeamSharingPolicies.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team_policies{
///TeamSharingPolicies

TeamSharingPolicies::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void TeamSharingPolicies::toJson(QJsonObject& js)const{

    m_shared_folder_member_policy.toJson(js, "shared_folder_member_policy");
    m_shared_folder_join_policy.toJson(js, "shared_folder_join_policy");
    m_shared_link_create_policy.toJson(js, "shared_link_create_policy");
}

void TeamSharingPolicies::fromJson(const QJsonObject& js){

    m_shared_folder_member_policy.fromJson(js["shared_folder_member_policy"].toObject());
    m_shared_folder_join_policy.fromJson(js["shared_folder_join_policy"].toObject());
    m_shared_link_create_policy.fromJson(js["shared_link_create_policy"].toObject());
}

QString TeamSharingPolicies::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<TeamSharingPolicies>  TeamSharingPolicies::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<TeamSharingPolicies>  TeamSharingPolicies::factory::create(const QJsonObject& js)
{
    std::unique_ptr<TeamSharingPolicies> rv;
    rv = std::unique_ptr<TeamSharingPolicies>(new TeamSharingPolicies);
    rv->fromJson(js);
    return rv;
}

}//team_policies
}//dropboxQt
