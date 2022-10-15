/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingLinkPermissions.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///LinkPermissions

LinkPermissions::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void LinkPermissions::toJson(QJsonObject& js)const{

    m_resolved_visibility.toJson(js, "resolved_visibility");
    m_requested_visibility.toJson(js, "requested_visibility");
    js["can_revoke"] = m_can_revoke;
    m_revoke_failure_reason.toJson(js, "revoke_failure_reason");
}

void LinkPermissions::fromJson(const QJsonObject& js){

    m_resolved_visibility.fromJson(js["resolved_visibility"].toObject());
    m_requested_visibility.fromJson(js["requested_visibility"].toObject());
    m_can_revoke = js["can_revoke"].toVariant().toBool();
    m_revoke_failure_reason.fromJson(js["revoke_failure_reason"].toObject());
}

QString LinkPermissions::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<LinkPermissions>  LinkPermissions::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<LinkPermissions>  LinkPermissions::factory::create(const QJsonObject& js)
{
    std::unique_ptr<LinkPermissions> rv;
    rv = std::unique_ptr<LinkPermissions>(new LinkPermissions);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
