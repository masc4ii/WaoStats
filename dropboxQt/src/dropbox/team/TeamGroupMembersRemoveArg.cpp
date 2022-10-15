/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMembersRemoveArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupMembersRemoveArg

GroupMembersRemoveArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMembersRemoveArg::toJson(QJsonObject& js)const{

    IncludeMembersArg::toJson(js);
    m_group.toJson(js, "group");
    js["users"] = struct_list2jsonarray(m_users);
}

void GroupMembersRemoveArg::fromJson(const QJsonObject& js){

    IncludeMembersArg::fromJson(js);
    m_group.fromJson(js["group"].toObject());
    jsonarray2struct_list(js["users"].toArray(), m_users);
}

QString GroupMembersRemoveArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMembersRemoveArg>  GroupMembersRemoveArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMembersRemoveArg>  GroupMembersRemoveArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMembersRemoveArg> rv;
    rv = std::unique_ptr<GroupMembersRemoveArg>(new GroupMembersRemoveArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
