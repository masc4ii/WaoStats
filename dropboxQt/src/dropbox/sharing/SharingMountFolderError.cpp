/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMountFolderError.h"

namespace dropboxQt{

namespace sharing{
///MountFolderError

MountFolderError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MountFolderError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MountFolderError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case MountFolderError_INSIDE_SHARED_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("inside_shared_folder");
        }break;
        case MountFolderError_INSUFFICIENT_QUOTA:{
            if(!name.isEmpty())
                js[name] = QString("insufficient_quota");
            js["insufficient_quota"] = (QJsonObject)m_insufficient_quota;
        }break;
        case MountFolderError_ALREADY_MOUNTED:{
            if(!name.isEmpty())
                js[name] = QString("already_mounted");
        }break;
        case MountFolderError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case MountFolderError_NOT_MOUNTABLE:{
            if(!name.isEmpty())
                js[name] = QString("not_mountable");
        }break;
        case MountFolderError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MountFolderError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = MountFolderError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("inside_shared_folder") == 0){
        m_tag = MountFolderError_INSIDE_SHARED_FOLDER;

    }
    else if(s.compare("insufficient_quota") == 0){
        m_tag = MountFolderError_INSUFFICIENT_QUOTA;
        m_insufficient_quota.fromJson(js["insufficient_quota"].toObject());
    }
    else if(s.compare("already_mounted") == 0){
        m_tag = MountFolderError_ALREADY_MOUNTED;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = MountFolderError_NO_PERMISSION;

    }
    else if(s.compare("not_mountable") == 0){
        m_tag = MountFolderError_NOT_MOUNTABLE;

    }
    else if(s.compare("other") == 0){
        m_tag = MountFolderError_OTHER;

    }
}

QString MountFolderError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MountFolderError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MountFolderError>  MountFolderError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MountFolderError> rv = std::unique_ptr<MountFolderError>(new MountFolderError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
