/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMemberDevicesArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMemberDevicesArg

ListMemberDevicesArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMemberDevicesArg::toJson(QJsonObject& js)const{

    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
    js["include_web_sessions"] = m_include_web_sessions;
    js["include_desktop_clients"] = m_include_desktop_clients;
    js["include_mobile_clients"] = m_include_mobile_clients;
}

void ListMemberDevicesArg::fromJson(const QJsonObject& js){

    m_team_member_id = js["team_member_id"].toString();
    m_include_web_sessions = js["include_web_sessions"].toVariant().toBool();
    m_include_desktop_clients = js["include_desktop_clients"].toVariant().toBool();
    m_include_mobile_clients = js["include_mobile_clients"].toVariant().toBool();
}

QString ListMemberDevicesArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMemberDevicesArg>  ListMemberDevicesArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMemberDevicesArg>  ListMemberDevicesArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMemberDevicesArg> rv;
    rv = std::unique_ptr<ListMemberDevicesArg>(new ListMemberDevicesArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
