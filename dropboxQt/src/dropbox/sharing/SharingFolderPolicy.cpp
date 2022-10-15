/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFolderPolicy.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///FolderPolicy

FolderPolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FolderPolicy::toJson(QJsonObject& js)const{

    m_member_policy.toJson(js, "member_policy");
    m_resolved_member_policy.toJson(js, "resolved_member_policy");
    m_acl_update_policy.toJson(js, "acl_update_policy");
    m_shared_link_policy.toJson(js, "shared_link_policy");
}

void FolderPolicy::fromJson(const QJsonObject& js){

    m_member_policy.fromJson(js["member_policy"].toObject());
    m_resolved_member_policy.fromJson(js["resolved_member_policy"].toObject());
    m_acl_update_policy.fromJson(js["acl_update_policy"].toObject());
    m_shared_link_policy.fromJson(js["shared_link_policy"].toObject());
}

QString FolderPolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FolderPolicy>  FolderPolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FolderPolicy>  FolderPolicy::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FolderPolicy> rv;
    rv = std::unique_ptr<FolderPolicy>(new FolderPolicy);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
