/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListTeamAppsArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListTeamAppsArg

ListTeamAppsArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListTeamAppsArg::toJson(QJsonObject& js)const{

    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListTeamAppsArg::fromJson(const QJsonObject& js){

    m_cursor = js["cursor"].toString();
}

QString ListTeamAppsArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListTeamAppsArg>  ListTeamAppsArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListTeamAppsArg>  ListTeamAppsArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListTeamAppsArg> rv;
    rv = std::unique_ptr<ListTeamAppsArg>(new ListTeamAppsArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
