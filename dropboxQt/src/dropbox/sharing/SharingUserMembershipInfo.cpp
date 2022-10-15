/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUserMembershipInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///UserMembershipInfo

UserMembershipInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UserMembershipInfo::toJson(QJsonObject& js)const{

    MembershipInfo::toJson(js);
    js["user"] = (QJsonObject)m_user;
}

void UserMembershipInfo::fromJson(const QJsonObject& js){

    MembershipInfo::fromJson(js);
    m_user.fromJson(js["user"].toObject());
}

QString UserMembershipInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UserMembershipInfo>  UserMembershipInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UserMembershipInfo>  UserMembershipInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UserMembershipInfo> rv;
    rv = std::unique_ptr<UserMembershipInfo>(new UserMembershipInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
