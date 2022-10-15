/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsMembersListArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupsMembersListArg

GroupsMembersListArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupsMembersListArg::toJson(QJsonObject& js)const{

    m_group.toJson(js, "group");
    js["limit"] = QString("%1").arg(m_limit);
}

void GroupsMembersListArg::fromJson(const QJsonObject& js){

    m_group.fromJson(js["group"].toObject());
    m_limit = js["limit"].toVariant().toString().toULongLong();
}

QString GroupsMembersListArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupsMembersListArg>  GroupsMembersListArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupsMembersListArg>  GroupsMembersListArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupsMembersListArg> rv;
    rv = std::unique_ptr<GroupsMembersListArg>(new GroupsMembersListArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
