/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMemberAppsArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMemberAppsArg

ListMemberAppsArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMemberAppsArg::toJson(QJsonObject& js)const{

    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
}

void ListMemberAppsArg::fromJson(const QJsonObject& js){

    m_team_member_id = js["team_member_id"].toString();
}

QString ListMemberAppsArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMemberAppsArg>  ListMemberAppsArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMemberAppsArg>  ListMemberAppsArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMemberAppsArg> rv;
    rv = std::unique_ptr<ListMemberAppsArg>(new ListMemberAppsArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
