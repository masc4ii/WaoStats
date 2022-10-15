/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMemberDevices.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MemberDevices

MemberDevices::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MemberDevices::toJson(QJsonObject& js)const{

    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
    js["web_sessions"] = struct_list2jsonarray(m_web_sessions);
    js["desktop_clients"] = struct_list2jsonarray(m_desktop_clients);
    js["mobile_clients"] = struct_list2jsonarray(m_mobile_clients);
}

void MemberDevices::fromJson(const QJsonObject& js){

    m_team_member_id = js["team_member_id"].toString();
    jsonarray2struct_list(js["web_sessions"].toArray(), m_web_sessions);
    jsonarray2struct_list(js["desktop_clients"].toArray(), m_desktop_clients);
    jsonarray2struct_list(js["mobile_clients"].toArray(), m_mobile_clients);
}

QString MemberDevices::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MemberDevices>  MemberDevices::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MemberDevices>  MemberDevices::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MemberDevices> rv;
    rv = std::unique_ptr<MemberDevices>(new MemberDevices);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
