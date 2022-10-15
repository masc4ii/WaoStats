/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharingFileAccessError.h"

namespace dropboxQt{

namespace sharing{
///SharingFileAccessError

SharingFileAccessError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharingFileAccessError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharingFileAccessError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case SharingFileAccessError_INVALID_FILE:{
            if(!name.isEmpty())
                js[name] = QString("invalid_file");
        }break;
        case SharingFileAccessError_IS_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("is_folder");
        }break;
        case SharingFileAccessError_INSIDE_PUBLIC_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("inside_public_folder");
        }break;
        case SharingFileAccessError_INSIDE_OSX_PACKAGE:{
            if(!name.isEmpty())
                js[name] = QString("inside_osx_package");
        }break;
        case SharingFileAccessError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharingFileAccessError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("no_permission") == 0){
        m_tag = SharingFileAccessError_NO_PERMISSION;

    }
    else if(s.compare("invalid_file") == 0){
        m_tag = SharingFileAccessError_INVALID_FILE;

    }
    else if(s.compare("is_folder") == 0){
        m_tag = SharingFileAccessError_IS_FOLDER;

    }
    else if(s.compare("inside_public_folder") == 0){
        m_tag = SharingFileAccessError_INSIDE_PUBLIC_FOLDER;

    }
    else if(s.compare("inside_osx_package") == 0){
        m_tag = SharingFileAccessError_INSIDE_OSX_PACKAGE;

    }
    else if(s.compare("other") == 0){
        m_tag = SharingFileAccessError_OTHER;

    }
}

QString SharingFileAccessError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharingFileAccessError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharingFileAccessError>  SharingFileAccessError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharingFileAccessError> rv = std::unique_ptr<SharingFileAccessError>(new SharingFileAccessError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
