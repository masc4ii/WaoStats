/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDeviceSessionError.h"

namespace dropboxQt{

namespace team{
///RevokeDeviceSessionError

RevokeDeviceSessionError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RevokeDeviceSessionError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RevokeDeviceSessionError_DEVICE_SESSION_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("device_session_not_found");
        }break;
        case RevokeDeviceSessionError_MEMBER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("member_not_found");
        }break;
        case RevokeDeviceSessionError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RevokeDeviceSessionError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("device_session_not_found") == 0){
        m_tag = RevokeDeviceSessionError_DEVICE_SESSION_NOT_FOUND;

    }
    else if(s.compare("member_not_found") == 0){
        m_tag = RevokeDeviceSessionError_MEMBER_NOT_FOUND;

    }
    else if(s.compare("other") == 0){
        m_tag = RevokeDeviceSessionError_OTHER;

    }
}

QString RevokeDeviceSessionError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RevokeDeviceSessionError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RevokeDeviceSessionError>  RevokeDeviceSessionError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RevokeDeviceSessionError> rv = std::unique_ptr<RevokeDeviceSessionError>(new RevokeDeviceSessionError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
