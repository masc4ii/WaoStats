/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMemberAppsResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMemberAppsResult

ListMemberAppsResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMemberAppsResult::toJson(QJsonObject& js)const{

    js["linked_api_apps"] = struct_list2jsonarray(m_linked_api_apps);
}

void ListMemberAppsResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["linked_api_apps"].toArray(), m_linked_api_apps);
}

QString ListMemberAppsResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMemberAppsResult>  ListMemberAppsResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMemberAppsResult>  ListMemberAppsResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMemberAppsResult> rv;
    rv = std::unique_ptr<ListMemberAppsResult>(new ListMemberAppsResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
