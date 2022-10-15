/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingInviteeMembershipInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///InviteeMembershipInfo

InviteeMembershipInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void InviteeMembershipInfo::toJson(QJsonObject& js)const{

    MembershipInfo::toJson(js);
    m_invitee.toJson(js, "invitee");
    js["user"] = (QJsonObject)m_user;
}

void InviteeMembershipInfo::fromJson(const QJsonObject& js){

    MembershipInfo::fromJson(js);
    m_invitee.fromJson(js["invitee"].toObject());
    m_user.fromJson(js["user"].toObject());
}

QString InviteeMembershipInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<InviteeMembershipInfo>  InviteeMembershipInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<InviteeMembershipInfo>  InviteeMembershipInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<InviteeMembershipInfo> rv;
    rv = std::unique_ptr<InviteeMembershipInfo>(new InviteeMembershipInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
