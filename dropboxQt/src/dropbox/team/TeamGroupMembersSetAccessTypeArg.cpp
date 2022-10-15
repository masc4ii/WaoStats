/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMembersSetAccessTypeArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupMembersSetAccessTypeArg

GroupMembersSetAccessTypeArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMembersSetAccessTypeArg::toJson(QJsonObject& js)const{

    GroupMemberSelector::toJson(js);
    m_access_type.toJson(js, "access_type");
    js["return_members"] = m_return_members;
}

void GroupMembersSetAccessTypeArg::fromJson(const QJsonObject& js){

    GroupMemberSelector::fromJson(js);
    m_access_type.fromJson(js["access_type"].toObject());
    m_return_members = js["return_members"].toVariant().toBool();
}

QString GroupMembersSetAccessTypeArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMembersSetAccessTypeArg>  GroupMembersSetAccessTypeArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMembersSetAccessTypeArg>  GroupMembersSetAccessTypeArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMembersSetAccessTypeArg> rv;
    rv = std::unique_ptr<GroupMembersSetAccessTypeArg>(new GroupMembersSetAccessTypeArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
