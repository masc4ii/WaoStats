/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMembersAppsResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMembersAppsResult

ListMembersAppsResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMembersAppsResult::toJson(QJsonObject& js)const{

    js["apps"] = struct_list2jsonarray(m_apps);
    js["has_more"] = m_has_more;
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListMembersAppsResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["apps"].toArray(), m_apps);
    m_has_more = js["has_more"].toVariant().toBool();
    m_cursor = js["cursor"].toString();
}

QString ListMembersAppsResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMembersAppsResult>  ListMembersAppsResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMembersAppsResult>  ListMembersAppsResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMembersAppsResult> rv;
    rv = std::unique_ptr<ListMembersAppsResult>(new ListMembersAppsResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
