/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGroupMembershipInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GroupMembershipInfo

GroupMembershipInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMembershipInfo::toJson(QJsonObject& js)const{

    MembershipInfo::toJson(js);
    js["group"] = (QJsonObject)m_group;
}

void GroupMembershipInfo::fromJson(const QJsonObject& js){

    MembershipInfo::fromJson(js);
    m_group.fromJson(js["group"].toObject());
}

QString GroupMembershipInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMembershipInfo>  GroupMembershipInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMembershipInfo>  GroupMembershipInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMembershipInfo> rv;
    rv = std::unique_ptr<GroupMembershipInfo>(new GroupMembershipInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
