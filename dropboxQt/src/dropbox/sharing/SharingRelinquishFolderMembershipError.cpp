/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRelinquishFolderMembershipError.h"

namespace dropboxQt{

namespace sharing{
///RelinquishFolderMembershipError

RelinquishFolderMembershipError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RelinquishFolderMembershipError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RelinquishFolderMembershipError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case RelinquishFolderMembershipError_FOLDER_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("folder_owner");
        }break;
        case RelinquishFolderMembershipError_MOUNTED:{
            if(!name.isEmpty())
                js[name] = QString("mounted");
        }break;
        case RelinquishFolderMembershipError_GROUP_ACCESS:{
            if(!name.isEmpty())
                js[name] = QString("group_access");
        }break;
        case RelinquishFolderMembershipError_TEAM_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("team_folder");
        }break;
        case RelinquishFolderMembershipError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case RelinquishFolderMembershipError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RelinquishFolderMembershipError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = RelinquishFolderMembershipError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("folder_owner") == 0){
        m_tag = RelinquishFolderMembershipError_FOLDER_OWNER;

    }
    else if(s.compare("mounted") == 0){
        m_tag = RelinquishFolderMembershipError_MOUNTED;

    }
    else if(s.compare("group_access") == 0){
        m_tag = RelinquishFolderMembershipError_GROUP_ACCESS;

    }
    else if(s.compare("team_folder") == 0){
        m_tag = RelinquishFolderMembershipError_TEAM_FOLDER;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = RelinquishFolderMembershipError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = RelinquishFolderMembershipError_OTHER;

    }
}

QString RelinquishFolderMembershipError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RelinquishFolderMembershipError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RelinquishFolderMembershipError>  RelinquishFolderMembershipError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RelinquishFolderMembershipError> rv = std::unique_ptr<RelinquishFolderMembershipError>(new RelinquishFolderMembershipError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
