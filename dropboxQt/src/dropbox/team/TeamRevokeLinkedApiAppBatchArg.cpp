/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeLinkedApiAppBatchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeLinkedApiAppBatchArg

RevokeLinkedApiAppBatchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeLinkedApiAppBatchArg::toJson(QJsonObject& js)const{

    js["revoke_linked_app"] = struct_list2jsonarray(m_revoke_linked_app);
}

void RevokeLinkedApiAppBatchArg::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["revoke_linked_app"].toArray(), m_revoke_linked_app);
}

QString RevokeLinkedApiAppBatchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeLinkedApiAppBatchArg>  RevokeLinkedApiAppBatchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeLinkedApiAppBatchArg>  RevokeLinkedApiAppBatchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeLinkedApiAppBatchArg> rv;
    rv = std::unique_ptr<RevokeLinkedApiAppBatchArg>(new RevokeLinkedApiAppBatchArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
