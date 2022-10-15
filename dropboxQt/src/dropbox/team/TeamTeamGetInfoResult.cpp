/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamTeamGetInfoResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///TeamGetInfoResult

TeamGetInfoResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void TeamGetInfoResult::toJson(QJsonObject& js)const{

    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(!m_team_id.isEmpty())
        js["team_id"] = QString(m_team_id);
    js["num_licensed_users"] = QString("%1").arg(m_num_licensed_users);
    js["num_provisioned_users"] = QString("%1").arg(m_num_provisioned_users);
    js["policies"] = (QJsonObject)m_policies;
}

void TeamGetInfoResult::fromJson(const QJsonObject& js){

    m_name = js["name"].toString();
    m_team_id = js["team_id"].toString();
    m_num_licensed_users = js["num_licensed_users"].toVariant().toString().toULongLong();
    m_num_provisioned_users = js["num_provisioned_users"].toVariant().toString().toULongLong();
    m_policies.fromJson(js["policies"].toObject());
}

QString TeamGetInfoResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<TeamGetInfoResult>  TeamGetInfoResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<TeamGetInfoResult>  TeamGetInfoResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<TeamGetInfoResult> rv;
    rv = std::unique_ptr<TeamGetInfoResult>(new TeamGetInfoResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
