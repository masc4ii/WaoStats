/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMembersDevicesArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMembersDevicesArg

ListMembersDevicesArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMembersDevicesArg::toJson(QJsonObject& js)const{

    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
    js["include_web_sessions"] = m_include_web_sessions;
    js["include_desktop_clients"] = m_include_desktop_clients;
    js["include_mobile_clients"] = m_include_mobile_clients;
}

void ListMembersDevicesArg::fromJson(const QJsonObject& js){

    m_cursor = js["cursor"].toString();
    m_include_web_sessions = js["include_web_sessions"].toVariant().toBool();
    m_include_desktop_clients = js["include_desktop_clients"].toVariant().toBool();
    m_include_mobile_clients = js["include_mobile_clients"].toVariant().toBool();
}

QString ListMembersDevicesArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMembersDevicesArg>  ListMembersDevicesArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMembersDevicesArg>  ListMembersDevicesArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMembersDevicesArg> rv;
    rv = std::unique_ptr<ListMembersDevicesArg>(new ListMembersDevicesArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
