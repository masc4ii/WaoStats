/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamActiveWebSession.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ActiveWebSession

ActiveWebSession::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ActiveWebSession::toJson(QJsonObject& js)const{

    DeviceSession::toJson(js);
    if(!m_user_agent.isEmpty())
        js["user_agent"] = QString(m_user_agent);
    if(!m_os.isEmpty())
        js["os"] = QString(m_os);
    if(!m_browser.isEmpty())
        js["browser"] = QString(m_browser);
}

void ActiveWebSession::fromJson(const QJsonObject& js){

    DeviceSession::fromJson(js);
    m_user_agent = js["user_agent"].toString();
    m_os = js["os"].toString();
    m_browser = js["browser"].toString();
}

QString ActiveWebSession::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ActiveWebSession>  ActiveWebSession::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ActiveWebSession>  ActiveWebSession::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ActiveWebSession> rv;
    rv = std::unique_ptr<ActiveWebSession>(new ActiveWebSession);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
