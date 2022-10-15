/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedLinkSettingsError.h"

namespace dropboxQt{

namespace sharing{
///SharedLinkSettingsError

SharedLinkSettingsError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedLinkSettingsError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedLinkSettingsError_INVALID_SETTINGS:{
            if(!name.isEmpty())
                js[name] = QString("invalid_settings");
        }break;
        case SharedLinkSettingsError_NOT_AUTHORIZED:{
            if(!name.isEmpty())
                js[name] = QString("not_authorized");
        }break;
    }//switch
}

void SharedLinkSettingsError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_settings") == 0){
        m_tag = SharedLinkSettingsError_INVALID_SETTINGS;

    }
    else if(s.compare("not_authorized") == 0){
        m_tag = SharedLinkSettingsError_NOT_AUTHORIZED;

    }
}

QString SharedLinkSettingsError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedLinkSettingsError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedLinkSettingsError>  SharedLinkSettingsError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedLinkSettingsError> rv = std::unique_ptr<SharedLinkSettingsError>(new SharedLinkSettingsError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
