/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMembersSelector.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupMembersSelector

GroupMembersSelector::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMembersSelector::toJson(QJsonObject& js)const{

    m_group.toJson(js, "group");
    m_users.toJson(js, "users");
}

void GroupMembersSelector::fromJson(const QJsonObject& js){

    m_group.fromJson(js["group"].toObject());
    m_users.fromJson(js["users"].toObject());
}

QString GroupMembersSelector::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMembersSelector>  GroupMembersSelector::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMembersSelector>  GroupMembersSelector::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMembersSelector> rv;
    rv = std::unique_ptr<GroupMembersSelector>(new GroupMembersSelector);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
