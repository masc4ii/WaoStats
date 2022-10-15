/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDeviceSessionStatus.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeDeviceSessionStatus

RevokeDeviceSessionStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeDeviceSessionStatus::toJson(QJsonObject& js)const{

    js["success"] = m_success;
    m_error_type.toJson(js, "error_type");
}

void RevokeDeviceSessionStatus::fromJson(const QJsonObject& js){

    m_success = js["success"].toVariant().toBool();
    m_error_type.fromJson(js["error_type"].toObject());
}

QString RevokeDeviceSessionStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeDeviceSessionStatus>  RevokeDeviceSessionStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeDeviceSessionStatus>  RevokeDeviceSessionStatus::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeDeviceSessionStatus> rv;
    rv = std::unique_ptr<RevokeDeviceSessionStatus>(new RevokeDeviceSessionStatus);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
