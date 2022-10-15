/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "auth"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/auth/AuthAuthError.h"

namespace dropboxQt{

namespace auth{
///AuthError

AuthError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AuthError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AuthError_INVALID_ACCESS_TOKEN:{
            if(!name.isEmpty())
                js[name] = QString("invalid_access_token");
        }break;
        case AuthError_INVALID_SELECT_USER:{
            if(!name.isEmpty())
                js[name] = QString("invalid_select_user");
        }break;
        case AuthError_INVALID_SELECT_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("invalid_select_admin");
        }break;
        case AuthError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void AuthError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_access_token") == 0){
        m_tag = AuthError_INVALID_ACCESS_TOKEN;

    }
    else if(s.compare("invalid_select_user") == 0){
        m_tag = AuthError_INVALID_SELECT_USER;

    }
    else if(s.compare("invalid_select_admin") == 0){
        m_tag = AuthError_INVALID_SELECT_ADMIN;

    }
    else if(s.compare("other") == 0){
        m_tag = AuthError_OTHER;

    }
}

QString AuthError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AuthError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AuthError>  AuthError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AuthError> rv = std::unique_ptr<AuthError>(new AuthError);
    rv->fromJson(js);
    return rv;
}

}//auth
}//dropboxQt
