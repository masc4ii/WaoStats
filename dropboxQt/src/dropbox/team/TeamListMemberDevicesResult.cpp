/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMemberDevicesResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMemberDevicesResult

ListMemberDevicesResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMemberDevicesResult::toJson(QJsonObject& js)const{

    js["active_web_sessions"] = struct_list2jsonarray(m_active_web_sessions);
    js["desktop_client_sessions"] = struct_list2jsonarray(m_desktop_client_sessions);
    js["mobile_client_sessions"] = struct_list2jsonarray(m_mobile_client_sessions);
}

void ListMemberDevicesResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["active_web_sessions"].toArray(), m_active_web_sessions);
    jsonarray2struct_list(js["desktop_client_sessions"].toArray(), m_desktop_client_sessions);
    jsonarray2struct_list(js["mobile_client_sessions"].toArray(), m_mobile_client_sessions);
}

QString ListMemberDevicesResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMemberDevicesResult>  ListMemberDevicesResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMemberDevicesResult>  ListMemberDevicesResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMemberDevicesResult> rv;
    rv = std::unique_ptr<ListMemberDevicesResult>(new ListMemberDevicesResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
