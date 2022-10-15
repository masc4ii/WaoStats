/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupUpdateArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupUpdateArgs

GroupUpdateArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupUpdateArgs::toJson(QJsonObject& js)const{

    IncludeMembersArg::toJson(js);
    m_group.toJson(js, "group");
    if(!m_new_group_name.isEmpty())
        js["new_group_name"] = QString(m_new_group_name);
    if(!m_new_group_external_id.isEmpty())
        js["new_group_external_id"] = QString(m_new_group_external_id);
    m_new_group_management_type.toJson(js, "new_group_management_type");
}

void GroupUpdateArgs::fromJson(const QJsonObject& js){

    IncludeMembersArg::fromJson(js);
    m_group.fromJson(js["group"].toObject());
    m_new_group_name = js["new_group_name"].toString();
    m_new_group_external_id = js["new_group_external_id"].toString();
    m_new_group_management_type.fromJson(js["new_group_management_type"].toObject());
}

QString GroupUpdateArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupUpdateArgs>  GroupUpdateArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupUpdateArgs>  GroupUpdateArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupUpdateArgs> rv;
    rv = std::unique_ptr<GroupUpdateArgs>(new GroupUpdateArgs);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
