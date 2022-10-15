/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeLinkedAppBatchResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeLinkedAppBatchResult

RevokeLinkedAppBatchResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeLinkedAppBatchResult::toJson(QJsonObject& js)const{

    js["revoke_linked_app_status"] = struct_list2jsonarray(m_revoke_linked_app_status);
}

void RevokeLinkedAppBatchResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["revoke_linked_app_status"].toArray(), m_revoke_linked_app_status);
}

QString RevokeLinkedAppBatchResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeLinkedAppBatchResult>  RevokeLinkedAppBatchResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeLinkedAppBatchResult>  RevokeLinkedAppBatchResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeLinkedAppBatchResult> rv;
    rv = std::unique_ptr<RevokeLinkedAppBatchResult>(new RevokeLinkedAppBatchResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
