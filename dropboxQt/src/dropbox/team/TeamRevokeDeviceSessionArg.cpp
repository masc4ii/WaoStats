/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDeviceSessionArg.h"

namespace dropboxQt{

namespace team{
///RevokeDeviceSessionArg

RevokeDeviceSessionArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RevokeDeviceSessionArg::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RevokeDeviceSessionArg_WEB_SESSION:{
            if(!name.isEmpty())
                js[name] = QString("web_session");
            js["web_session"] = (QJsonObject)m_web_session;
        }break;
        case RevokeDeviceSessionArg_DESKTOP_CLIENT:{
            if(!name.isEmpty())
                js[name] = QString("desktop_client");
            js["desktop_client"] = (QJsonObject)m_desktop_client;
        }break;
        case RevokeDeviceSessionArg_MOBILE_CLIENT:{
            if(!name.isEmpty())
                js[name] = QString("mobile_client");
            js["mobile_client"] = (QJsonObject)m_mobile_client;
        }break;
    }//switch
}

void RevokeDeviceSessionArg::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("web_session") == 0){
        m_tag = RevokeDeviceSessionArg_WEB_SESSION;
        m_web_session.fromJson(js["web_session"].toObject());
    }
    else if(s.compare("desktop_client") == 0){
        m_tag = RevokeDeviceSessionArg_DESKTOP_CLIENT;
        m_desktop_client.fromJson(js["desktop_client"].toObject());
    }
    else if(s.compare("mobile_client") == 0){
        m_tag = RevokeDeviceSessionArg_MOBILE_CLIENT;
        m_mobile_client.fromJson(js["mobile_client"].toObject());
    }
}

QString RevokeDeviceSessionArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RevokeDeviceSessionArg");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RevokeDeviceSessionArg>  RevokeDeviceSessionArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RevokeDeviceSessionArg> rv = std::unique_ptr<RevokeDeviceSessionArg>(new RevokeDeviceSessionArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
