/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeLinkedApiAppArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeLinkedApiAppArg

RevokeLinkedApiAppArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeLinkedApiAppArg::toJson(QJsonObject& js)const{

    if(!m_app_id.isEmpty())
        js["app_id"] = QString(m_app_id);
    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
    js["keep_app_folder"] = m_keep_app_folder;
}

void RevokeLinkedApiAppArg::fromJson(const QJsonObject& js){

    m_app_id = js["app_id"].toString();
    m_team_member_id = js["team_member_id"].toString();
    m_keep_app_folder = js["keep_app_folder"].toVariant().toBool();
}

QString RevokeLinkedApiAppArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeLinkedApiAppArg>  RevokeLinkedApiAppArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeLinkedApiAppArg>  RevokeLinkedApiAppArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeLinkedApiAppArg> rv;
    rv = std::unique_ptr<RevokeLinkedApiAppArg>(new RevokeLinkedApiAppArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
