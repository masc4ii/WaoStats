/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMembersAddArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupMembersAddArg

GroupMembersAddArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMembersAddArg::toJson(QJsonObject& js)const{

    IncludeMembersArg::toJson(js);
    m_group.toJson(js, "group");
    js["members"] = struct_list2jsonarray(m_members);
}

void GroupMembersAddArg::fromJson(const QJsonObject& js){

    IncludeMembersArg::fromJson(js);
    m_group.fromJson(js["group"].toObject());
    jsonarray2struct_list(js["members"].toArray(), m_members);
}

QString GroupMembersAddArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMembersAddArg>  GroupMembersAddArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMembersAddArg>  GroupMembersAddArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMembersAddArg> rv;
    rv = std::unique_ptr<GroupMembersAddArg>(new GroupMembersAddArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
