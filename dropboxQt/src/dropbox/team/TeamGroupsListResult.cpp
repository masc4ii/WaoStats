/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsListResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupsListResult

GroupsListResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupsListResult::toJson(QJsonObject& js)const{

    js["groups"] = struct_list2jsonarray(m_groups);
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
    js["has_more"] = m_has_more;
}

void GroupsListResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["groups"].toArray(), m_groups);
    m_cursor = js["cursor"].toString();
    m_has_more = js["has_more"].toVariant().toBool();
}

QString GroupsListResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupsListResult>  GroupsListResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupsListResult>  GroupsListResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupsListResult> rv;
    rv = std::unique_ptr<GroupsListResult>(new GroupsListResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
