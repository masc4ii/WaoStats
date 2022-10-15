/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsMembersListResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupsMembersListResult

GroupsMembersListResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupsMembersListResult::toJson(QJsonObject& js)const{

    js["members"] = struct_list2jsonarray(m_members);
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
    js["has_more"] = m_has_more;
}

void GroupsMembersListResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["members"].toArray(), m_members);
    m_cursor = js["cursor"].toString();
    m_has_more = js["has_more"].toVariant().toBool();
}

QString GroupsMembersListResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupsMembersListResult>  GroupsMembersListResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupsMembersListResult>  GroupsMembersListResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupsMembersListResult> rv;
    rv = std::unique_ptr<GroupsMembersListResult>(new GroupsMembersListResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
