/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDeviceSessionBatchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeDeviceSessionBatchArg

RevokeDeviceSessionBatchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeDeviceSessionBatchArg::toJson(QJsonObject& js)const{

    js["revoke_devices"] = struct_list2jsonarray(m_revoke_devices);
}

void RevokeDeviceSessionBatchArg::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["revoke_devices"].toArray(), m_revoke_devices);
}

QString RevokeDeviceSessionBatchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeDeviceSessionBatchArg>  RevokeDeviceSessionBatchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeDeviceSessionBatchArg>  RevokeDeviceSessionBatchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeDeviceSessionBatchArg> rv;
    rv = std::unique_ptr<RevokeDeviceSessionBatchArg>(new RevokeDeviceSessionBatchArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
