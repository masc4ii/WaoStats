/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRemoveFolderMemberError.h"

namespace dropboxQt{

namespace sharing{
///RemoveFolderMemberError

RemoveFolderMemberError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RemoveFolderMemberError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RemoveFolderMemberError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case RemoveFolderMemberError_MEMBER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("member_error");
            m_member_error.toJson(js, "member_error");
        }break;
        case RemoveFolderMemberError_FOLDER_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("folder_owner");
        }break;
        case RemoveFolderMemberError_GROUP_ACCESS:{
            if(!name.isEmpty())
                js[name] = QString("group_access");
        }break;
        case RemoveFolderMemberError_TEAM_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("team_folder");
        }break;
        case RemoveFolderMemberError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case RemoveFolderMemberError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RemoveFolderMemberError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = RemoveFolderMemberError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("member_error") == 0){
        m_tag = RemoveFolderMemberError_MEMBER_ERROR;
        m_member_error.fromJson(js["member_error"].toObject());
    }
    else if(s.compare("folder_owner") == 0){
        m_tag = RemoveFolderMemberError_FOLDER_OWNER;

    }
    else if(s.compare("group_access") == 0){
        m_tag = RemoveFolderMemberError_GROUP_ACCESS;

    }
    else if(s.compare("team_folder") == 0){
        m_tag = RemoveFolderMemberError_TEAM_FOLDER;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = RemoveFolderMemberError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = RemoveFolderMemberError_OTHER;

    }
}

QString RemoveFolderMemberError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RemoveFolderMemberError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RemoveFolderMemberError>  RemoveFolderMemberError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RemoveFolderMemberError> rv = std::unique_ptr<RemoveFolderMemberError>(new RemoveFolderMemberError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
