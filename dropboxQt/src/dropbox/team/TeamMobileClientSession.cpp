/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMobileClientSession.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MobileClientSession

MobileClientSession::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MobileClientSession::toJson(QJsonObject& js)const{

    DeviceSession::toJson(js);
    if(!m_device_name.isEmpty())
        js["device_name"] = QString(m_device_name);
    m_client_type.toJson(js, "client_type");
    if(!m_client_version.isEmpty())
        js["client_version"] = QString(m_client_version);
    if(!m_os_version.isEmpty())
        js["os_version"] = QString(m_os_version);
    if(!m_last_carrier.isEmpty())
        js["last_carrier"] = QString(m_last_carrier);
}

void MobileClientSession::fromJson(const QJsonObject& js){

    DeviceSession::fromJson(js);
    m_device_name = js["device_name"].toString();
    m_client_type.fromJson(js["client_type"].toObject());
    m_client_version = js["client_version"].toString();
    m_os_version = js["os_version"].toString();
    m_last_carrier = js["last_carrier"].toString();
}

QString MobileClientSession::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MobileClientSession>  MobileClientSession::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MobileClientSession>  MobileClientSession::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MobileClientSession> rv;
    rv = std::unique_ptr<MobileClientSession>(new MobileClientSession);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
