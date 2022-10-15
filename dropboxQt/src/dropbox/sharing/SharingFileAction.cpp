/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFileAction.h"

namespace dropboxQt{

namespace sharing{
///FileAction

FileAction::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void FileAction::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case FileAction_EDIT_CONTENTS:{
            if(!name.isEmpty())
                js[name] = QString("edit_contents");
        }break;
        case FileAction_INVITE_VIEWER:{
            if(!name.isEmpty())
                js[name] = QString("invite_viewer");
        }break;
        case FileAction_INVITE_VIEWER_NO_COMMENT:{
            if(!name.isEmpty())
                js[name] = QString("invite_viewer_no_comment");
        }break;
        case FileAction_UNSHARE:{
            if(!name.isEmpty())
                js[name] = QString("unshare");
        }break;
        case FileAction_RELINQUISH_MEMBERSHIP:{
            if(!name.isEmpty())
                js[name] = QString("relinquish_membership");
        }break;
        case FileAction_SHARE_LINK:{
            if(!name.isEmpty())
                js[name] = QString("share_link");
        }break;
        case FileAction_CREATE_LINK:{
            if(!name.isEmpty())
                js[name] = QString("create_link");
        }break;
        case FileAction_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void FileAction::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("edit_contents") == 0){
        m_tag = FileAction_EDIT_CONTENTS;

    }
    else if(s.compare("invite_viewer") == 0){
        m_tag = FileAction_INVITE_VIEWER;

    }
    else if(s.compare("invite_viewer_no_comment") == 0){
        m_tag = FileAction_INVITE_VIEWER_NO_COMMENT;

    }
    else if(s.compare("unshare") == 0){
        m_tag = FileAction_UNSHARE;

    }
    else if(s.compare("relinquish_membership") == 0){
        m_tag = FileAction_RELINQUISH_MEMBERSHIP;

    }
    else if(s.compare("share_link") == 0){
        m_tag = FileAction_SHARE_LINK;

    }
    else if(s.compare("create_link") == 0){
        m_tag = FileAction_CREATE_LINK;

    }
    else if(s.compare("other") == 0){
        m_tag = FileAction_OTHER;

    }
}

QString FileAction::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "FileAction");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<FileAction>  FileAction::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<FileAction> rv = std::unique_ptr<FileAction>(new FileAction);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
