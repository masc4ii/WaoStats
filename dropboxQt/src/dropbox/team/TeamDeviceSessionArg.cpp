/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamDeviceSessionArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///DeviceSessionArg

DeviceSessionArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void DeviceSessionArg::toJson(QJsonObject& js)const{

    if(!m_session_id.isEmpty())
        js["session_id"] = QString(m_session_id);
    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
}

void DeviceSessionArg::fromJson(const QJsonObject& js){

    m_session_id = js["session_id"].toString();
    m_team_member_id = js["team_member_id"].toString();
}

QString DeviceSessionArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<DeviceSessionArg>  DeviceSessionArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<DeviceSessionArg>  DeviceSessionArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<DeviceSessionArg> rv;
    rv = std::unique_ptr<DeviceSessionArg>(new DeviceSessionArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
