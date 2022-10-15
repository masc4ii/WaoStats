/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharePathError.h"

namespace dropboxQt{

namespace sharing{
///SharePathError

SharePathError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharePathError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharePathError_IS_FILE:{
            if(!name.isEmpty())
                js[name] = QString("is_file");
        }break;
        case SharePathError_INSIDE_SHARED_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("inside_shared_folder");
        }break;
        case SharePathError_CONTAINS_SHARED_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("contains_shared_folder");
        }break;
        case SharePathError_IS_APP_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("is_app_folder");
        }break;
        case SharePathError_INSIDE_APP_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("inside_app_folder");
        }break;
        case SharePathError_IS_PUBLIC_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("is_public_folder");
        }break;
        case SharePathError_INSIDE_PUBLIC_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("inside_public_folder");
        }break;
        case SharePathError_ALREADY_SHARED:{
            if(!name.isEmpty())
                js[name] = QString("already_shared");
            js["already_shared"] = (QJsonObject)m_already_shared;
        }break;
        case SharePathError_INVALID_PATH:{
            if(!name.isEmpty())
                js[name] = QString("invalid_path");
        }break;
        case SharePathError_IS_OSX_PACKAGE:{
            if(!name.isEmpty())
                js[name] = QString("is_osx_package");
        }break;
        case SharePathError_INSIDE_OSX_PACKAGE:{
            if(!name.isEmpty())
                js[name] = QString("inside_osx_package");
        }break;
        case SharePathError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharePathError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("is_file") == 0){
        m_tag = SharePathError_IS_FILE;

    }
    else if(s.compare("inside_shared_folder") == 0){
        m_tag = SharePathError_INSIDE_SHARED_FOLDER;

    }
    else if(s.compare("contains_shared_folder") == 0){
        m_tag = SharePathError_CONTAINS_SHARED_FOLDER;

    }
    else if(s.compare("is_app_folder") == 0){
        m_tag = SharePathError_IS_APP_FOLDER;

    }
    else if(s.compare("inside_app_folder") == 0){
        m_tag = SharePathError_INSIDE_APP_FOLDER;

    }
    else if(s.compare("is_public_folder") == 0){
        m_tag = SharePathError_IS_PUBLIC_FOLDER;

    }
    else if(s.compare("inside_public_folder") == 0){
        m_tag = SharePathError_INSIDE_PUBLIC_FOLDER;

    }
    else if(s.compare("already_shared") == 0){
        m_tag = SharePathError_ALREADY_SHARED;
        m_already_shared.fromJson(js["already_shared"].toObject());
    }
    else if(s.compare("invalid_path") == 0){
        m_tag = SharePathError_INVALID_PATH;

    }
    else if(s.compare("is_osx_package") == 0){
        m_tag = SharePathError_IS_OSX_PACKAGE;

    }
    else if(s.compare("inside_osx_package") == 0){
        m_tag = SharePathError_INSIDE_OSX_PACKAGE;

    }
    else if(s.compare("other") == 0){
        m_tag = SharePathError_OTHER;

    }
}

QString SharePathError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharePathError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharePathError>  SharePathError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharePathError> rv = std::unique_ptr<SharePathError>(new SharePathError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
