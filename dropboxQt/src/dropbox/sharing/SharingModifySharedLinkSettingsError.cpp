/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingModifySharedLinkSettingsError.h"

namespace dropboxQt{

namespace sharing{
///ModifySharedLinkSettingsError

ModifySharedLinkSettingsError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ModifySharedLinkSettingsError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedLinkError_SHARED_LINK_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("shared_link_not_found");
        }break;
        case SharedLinkError_SHARED_LINK_ACCESS_DENIED:{
            if(!name.isEmpty())
                js[name] = QString("shared_link_access_denied");
        }break;
        case SharedLinkError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case ModifySharedLinkSettingsError_SETTINGS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("settings_error");
            m_settings_error.toJson(js, "settings_error");
        }break;
        case ModifySharedLinkSettingsError_EMAIL_NOT_VERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("email_not_verified");
        }break;
    }//switch
}

void ModifySharedLinkSettingsError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("shared_link_not_found") == 0){
        m_tag = SharedLinkError_SHARED_LINK_NOT_FOUND;

    }
    else if(s.compare("shared_link_access_denied") == 0){
        m_tag = SharedLinkError_SHARED_LINK_ACCESS_DENIED;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedLinkError_OTHER;

    }
    if(s.compare("settings_error") == 0){
        m_tag = ModifySharedLinkSettingsError_SETTINGS_ERROR;
        m_settings_error.fromJson(js["settings_error"].toObject());
    }
    else if(s.compare("email_not_verified") == 0){
        m_tag = ModifySharedLinkSettingsError_EMAIL_NOT_VERIFIED;

    }
}

QString ModifySharedLinkSettingsError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ModifySharedLinkSettingsError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ModifySharedLinkSettingsError>  ModifySharedLinkSettingsError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ModifySharedLinkSettingsError> rv = std::unique_ptr<ModifySharedLinkSettingsError>(new ModifySharedLinkSettingsError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
