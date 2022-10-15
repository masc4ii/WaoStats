/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMembersAppsArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMembersAppsArg

ListMembersAppsArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMembersAppsArg::toJson(QJsonObject& js)const{

    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListMembersAppsArg::fromJson(const QJsonObject& js){

    m_cursor = js["cursor"].toString();
}

QString ListMembersAppsArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMembersAppsArg>  ListMembersAppsArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMembersAppsArg>  ListMembersAppsArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMembersAppsArg> rv;
    rv = std::unique_ptr<ListMembersAppsArg>(new ListMembersAppsArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
