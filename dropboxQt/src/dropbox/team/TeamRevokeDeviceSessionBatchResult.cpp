/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDeviceSessionBatchResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeDeviceSessionBatchResult

RevokeDeviceSessionBatchResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeDeviceSessionBatchResult::toJson(QJsonObject& js)const{

    js["revoke_devices_status"] = struct_list2jsonarray(m_revoke_devices_status);
}

void RevokeDeviceSessionBatchResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["revoke_devices_status"].toArray(), m_revoke_devices_status);
}

QString RevokeDeviceSessionBatchResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeDeviceSessionBatchResult>  RevokeDeviceSessionBatchResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeDeviceSessionBatchResult>  RevokeDeviceSessionBatchResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeDeviceSessionBatchResult> rv;
    rv = std::unique_ptr<RevokeDeviceSessionBatchResult>(new RevokeDeviceSessionBatchResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
