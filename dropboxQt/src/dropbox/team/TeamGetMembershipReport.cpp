/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGetMembershipReport.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GetMembershipReport

GetMembershipReport::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetMembershipReport::toJson(QJsonObject& js)const{

    BaseDfbReport::toJson(js);
    js["team_size"] = ingrl_list2jsonarray(m_team_size);
    js["pending_invites"] = ingrl_list2jsonarray(m_pending_invites);
    js["members_joined"] = ingrl_list2jsonarray(m_members_joined);
    js["suspended_members"] = ingrl_list2jsonarray(m_suspended_members);
    js["licenses"] = ingrl_list2jsonarray(m_licenses);
}

void GetMembershipReport::fromJson(const QJsonObject& js){

    BaseDfbReport::fromJson(js);
    jsonarray2ingrl_list(js["team_size"].toArray(), m_team_size);
    jsonarray2ingrl_list(js["pending_invites"].toArray(), m_pending_invites);
    jsonarray2ingrl_list(js["members_joined"].toArray(), m_members_joined);
    jsonarray2ingrl_list(js["suspended_members"].toArray(), m_suspended_members);
    jsonarray2ingrl_list(js["licenses"].toArray(), m_licenses);
}

QString GetMembershipReport::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetMembershipReport>  GetMembershipReport::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetMembershipReport>  GetMembershipReport::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetMembershipReport> rv;
    rv = std::unique_ptr<GetMembershipReport>(new GetMembershipReport);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
