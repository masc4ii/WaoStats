/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingCreateSharedLinkWithSettingsError.h"

namespace dropboxQt{

namespace sharing{
///CreateSharedLinkWithSettingsError

CreateSharedLinkWithSettingsError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void CreateSharedLinkWithSettingsError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case CreateSharedLinkWithSettingsError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case CreateSharedLinkWithSettingsError_EMAIL_NOT_VERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("email_not_verified");
        }break;
        case CreateSharedLinkWithSettingsError_SHARED_LINK_ALREADY_EXISTS:{
            if(!name.isEmpty())
                js[name] = QString("shared_link_already_exists");
        }break;
        case CreateSharedLinkWithSettingsError_SETTINGS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("settings_error");
            m_settings_error.toJson(js, "settings_error");
        }break;
        case CreateSharedLinkWithSettingsError_ACCESS_DENIED:{
            if(!name.isEmpty())
                js[name] = QString("access_denied");
        }break;
    }//switch
}

void CreateSharedLinkWithSettingsError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = CreateSharedLinkWithSettingsError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("email_not_verified") == 0){
        m_tag = CreateSharedLinkWithSettingsError_EMAIL_NOT_VERIFIED;

    }
    else if(s.compare("shared_link_already_exists") == 0){
        m_tag = CreateSharedLinkWithSettingsError_SHARED_LINK_ALREADY_EXISTS;

    }
    else if(s.compare("settings_error") == 0){
        m_tag = CreateSharedLinkWithSettingsError_SETTINGS_ERROR;
        m_settings_error.fromJson(js["settings_error"].toObject());
    }
    else if(s.compare("access_denied") == 0){
        m_tag = CreateSharedLinkWithSettingsError_ACCESS_DENIED;

    }
}

QString CreateSharedLinkWithSettingsError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "CreateSharedLinkWithSettingsError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<CreateSharedLinkWithSettingsError>  CreateSharedLinkWithSettingsError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<CreateSharedLinkWithSettingsError> rv = std::unique_ptr<CreateSharedLinkWithSettingsError>(new CreateSharedLinkWithSettingsError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
