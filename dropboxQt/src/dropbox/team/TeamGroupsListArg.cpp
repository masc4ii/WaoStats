/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsListArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupsListArg

GroupsListArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupsListArg::toJson(QJsonObject& js)const{

    js["limit"] = QString("%1").arg(m_limit);
}

void GroupsListArg::fromJson(const QJsonObject& js){

    m_limit = js["limit"].toVariant().toString().toULongLong();
}

QString GroupsListArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupsListArg>  GroupsListArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupsListArg>  GroupsListArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupsListArg> rv;
    rv = std::unique_ptr<GroupsListArg>(new GroupsListArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
