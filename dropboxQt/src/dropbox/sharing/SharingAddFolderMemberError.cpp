/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAddFolderMemberError.h"

namespace dropboxQt{

namespace sharing{
///AddFolderMemberError

AddFolderMemberError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AddFolderMemberError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AddFolderMemberError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case AddFolderMemberError_EMAIL_UNVERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("email_unverified");
        }break;
        case AddFolderMemberError_BAD_MEMBER:{
            if(!name.isEmpty())
                js[name] = QString("bad_member");
            m_bad_member.toJson(js, "bad_member");
        }break;
        case AddFolderMemberError_CANT_SHARE_OUTSIDE_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("cant_share_outside_team");
        }break;
        case AddFolderMemberError_TOO_MANY_MEMBERS:{
            if(!name.isEmpty())
                js[name] = QString("too_many_members");
            js["too_many_members"] = QString("%1").arg(m_too_many_members);
        }break;
        case AddFolderMemberError_TOO_MANY_PENDING_INVITES:{
            if(!name.isEmpty())
                js[name] = QString("too_many_pending_invites");
            js["too_many_pending_invites"] = QString("%1").arg(m_too_many_pending_invites);
        }break;
        case AddFolderMemberError_RATE_LIMIT:{
            if(!name.isEmpty())
                js[name] = QString("rate_limit");
        }break;
        case AddFolderMemberError_TOO_MANY_INVITEES:{
            if(!name.isEmpty())
                js[name] = QString("too_many_invitees");
        }break;
        case AddFolderMemberError_INSUFFICIENT_PLAN:{
            if(!name.isEmpty())
                js[name] = QString("insufficient_plan");
        }break;
        case AddFolderMemberError_TEAM_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("team_folder");
        }break;
        case AddFolderMemberError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case AddFolderMemberError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void AddFolderMemberError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = AddFolderMemberError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("email_unverified") == 0){
        m_tag = AddFolderMemberError_EMAIL_UNVERIFIED;

    }
    else if(s.compare("bad_member") == 0){
        m_tag = AddFolderMemberError_BAD_MEMBER;
        m_bad_member.fromJson(js["bad_member"].toObject());
    }
    else if(s.compare("cant_share_outside_team") == 0){
        m_tag = AddFolderMemberError_CANT_SHARE_OUTSIDE_TEAM;

    }
    else if(s.compare("too_many_members") == 0){
        m_tag = AddFolderMemberError_TOO_MANY_MEMBERS;
        m_too_many_members = js["too_many_members"].toVariant().toString().toULongLong();
    }
    else if(s.compare("too_many_pending_invites") == 0){
        m_tag = AddFolderMemberError_TOO_MANY_PENDING_INVITES;
        m_too_many_pending_invites = js["too_many_pending_invites"].toVariant().toString().toULongLong();
    }
    else if(s.compare("rate_limit") == 0){
        m_tag = AddFolderMemberError_RATE_LIMIT;

    }
    else if(s.compare("too_many_invitees") == 0){
        m_tag = AddFolderMemberError_TOO_MANY_INVITEES;

    }
    else if(s.compare("insufficient_plan") == 0){
        m_tag = AddFolderMemberError_INSUFFICIENT_PLAN;

    }
    else if(s.compare("team_folder") == 0){
        m_tag = AddFolderMemberError_TEAM_FOLDER;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = AddFolderMemberError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = AddFolderMemberError_OTHER;

    }
}

QString AddFolderMemberError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AddFolderMemberError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AddFolderMemberError>  AddFolderMemberError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AddFolderMemberError> rv = std::unique_ptr<AddFolderMemberError>(new AddFolderMemberError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
