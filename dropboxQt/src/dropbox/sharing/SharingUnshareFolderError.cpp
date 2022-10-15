/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUnshareFolderError.h"

namespace dropboxQt{

namespace sharing{
///UnshareFolderError

UnshareFolderError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UnshareFolderError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UnshareFolderError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case UnshareFolderError_TEAM_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("team_folder");
        }break;
        case UnshareFolderError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case UnshareFolderError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void UnshareFolderError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = UnshareFolderError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("team_folder") == 0){
        m_tag = UnshareFolderError_TEAM_FOLDER;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = UnshareFolderError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = UnshareFolderError_OTHER;

    }
}

QString UnshareFolderError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UnshareFolderError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UnshareFolderError>  UnshareFolderError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UnshareFolderError> rv = std::unique_ptr<UnshareFolderError>(new UnshareFolderError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
