/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamDesktopClientSession.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///DesktopClientSession

DesktopClientSession::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void DesktopClientSession::toJson(QJsonObject& js)const{

    DeviceSession::toJson(js);
    if(!m_host_name.isEmpty())
        js["host_name"] = QString(m_host_name);
    m_client_type.toJson(js, "client_type");
    if(!m_client_version.isEmpty())
        js["client_version"] = QString(m_client_version);
    if(!m_platform.isEmpty())
        js["platform"] = QString(m_platform);
    js["is_delete_on_unlink_supported"] = m_is_delete_on_unlink_supported;
}

void DesktopClientSession::fromJson(const QJsonObject& js){

    DeviceSession::fromJson(js);
    m_host_name = js["host_name"].toString();
    m_client_type.fromJson(js["client_type"].toObject());
    m_client_version = js["client_version"].toString();
    m_platform = js["platform"].toString();
    m_is_delete_on_unlink_supported = js["is_delete_on_unlink_supported"].toVariant().toBool();
}

QString DesktopClientSession::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<DesktopClientSession>  DesktopClientSession::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<DesktopClientSession>  DesktopClientSession::factory::create(const QJsonObject& js)
{
    std::unique_ptr<DesktopClientSession> rv;
    rv = std::unique_ptr<DesktopClientSession>(new DesktopClientSession);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
