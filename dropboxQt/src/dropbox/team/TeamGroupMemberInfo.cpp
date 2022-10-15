/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMemberInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupMemberInfo

GroupMemberInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMemberInfo::toJson(QJsonObject& js)const{

    js["profile"] = (QJsonObject)m_profile;
    m_access_type.toJson(js, "access_type");
}

void GroupMemberInfo::fromJson(const QJsonObject& js){

    m_profile.fromJson(js["profile"].toObject());
    m_access_type.fromJson(js["access_type"].toObject());
}

QString GroupMemberInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMemberInfo>  GroupMemberInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMemberInfo>  GroupMemberInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMemberInfo> rv;
    rv = std::unique_ptr<GroupMemberInfo>(new GroupMemberInfo);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
