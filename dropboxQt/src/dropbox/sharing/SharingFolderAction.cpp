/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFolderAction.h"

namespace dropboxQt{

namespace sharing{
///FolderAction

FolderAction::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void FolderAction::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case FolderAction_CHANGE_OPTIONS:{
            if(!name.isEmpty())
                js[name] = QString("change_options");
        }break;
        case FolderAction_EDIT_CONTENTS:{
            if(!name.isEmpty())
                js[name] = QString("edit_contents");
        }break;
        case FolderAction_INVITE_EDITOR:{
            if(!name.isEmpty())
                js[name] = QString("invite_editor");
        }break;
        case FolderAction_INVITE_VIEWER:{
            if(!name.isEmpty())
                js[name] = QString("invite_viewer");
        }break;
        case FolderAction_INVITE_VIEWER_NO_COMMENT:{
            if(!name.isEmpty())
                js[name] = QString("invite_viewer_no_comment");
        }break;
        case FolderAction_RELINQUISH_MEMBERSHIP:{
            if(!name.isEmpty())
                js[name] = QString("relinquish_membership");
        }break;
        case FolderAction_UNMOUNT:{
            if(!name.isEmpty())
                js[name] = QString("unmount");
        }break;
        case FolderAction_UNSHARE:{
            if(!name.isEmpty())
                js[name] = QString("unshare");
        }break;
        case FolderAction_LEAVE_A_COPY:{
            if(!name.isEmpty())
                js[name] = QString("leave_a_copy");
        }break;
        case FolderAction_SHARE_LINK:{
            if(!name.isEmpty())
                js[name] = QString("share_link");
        }break;
        case FolderAction_CREATE_LINK:{
            if(!name.isEmpty())
                js[name] = QString("create_link");
        }break;
        case FolderAction_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void FolderAction::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("change_options") == 0){
        m_tag = FolderAction_CHANGE_OPTIONS;

    }
    else if(s.compare("edit_contents") == 0){
        m_tag = FolderAction_EDIT_CONTENTS;

    }
    else if(s.compare("invite_editor") == 0){
        m_tag = FolderAction_INVITE_EDITOR;

    }
    else if(s.compare("invite_viewer") == 0){
        m_tag = FolderAction_INVITE_VIEWER;

    }
    else if(s.compare("invite_viewer_no_comment") == 0){
        m_tag = FolderAction_INVITE_VIEWER_NO_COMMENT;

    }
    else if(s.compare("relinquish_membership") == 0){
        m_tag = FolderAction_RELINQUISH_MEMBERSHIP;

    }
    else if(s.compare("unmount") == 0){
        m_tag = FolderAction_UNMOUNT;

    }
    else if(s.compare("unshare") == 0){
        m_tag = FolderAction_UNSHARE;

    }
    else if(s.compare("leave_a_copy") == 0){
        m_tag = FolderAction_LEAVE_A_COPY;

    }
    else if(s.compare("share_link") == 0){
        m_tag = FolderAction_SHARE_LINK;

    }
    else if(s.compare("create_link") == 0){
        m_tag = FolderAction_CREATE_LINK;

    }
    else if(s.compare("other") == 0){
        m_tag = FolderAction_OTHER;

    }
}

QString FolderAction::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "FolderAction");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<FolderAction>  FolderAction::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<FolderAction> rv = std::unique_ptr<FolderAction>(new FolderAction);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
