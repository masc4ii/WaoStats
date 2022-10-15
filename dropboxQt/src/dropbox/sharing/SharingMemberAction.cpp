/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMemberAction.h"

namespace dropboxQt{

namespace sharing{
///MemberAction

MemberAction::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MemberAction::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MemberAction_LEAVE_A_COPY:{
            if(!name.isEmpty())
                js[name] = QString("leave_a_copy");
        }break;
        case MemberAction_MAKE_EDITOR:{
            if(!name.isEmpty())
                js[name] = QString("make_editor");
        }break;
        case MemberAction_MAKE_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("make_owner");
        }break;
        case MemberAction_MAKE_VIEWER:{
            if(!name.isEmpty())
                js[name] = QString("make_viewer");
        }break;
        case MemberAction_MAKE_VIEWER_NO_COMMENT:{
            if(!name.isEmpty())
                js[name] = QString("make_viewer_no_comment");
        }break;
        case MemberAction_REMOVE:{
            if(!name.isEmpty())
                js[name] = QString("remove");
        }break;
        case MemberAction_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MemberAction::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("leave_a_copy") == 0){
        m_tag = MemberAction_LEAVE_A_COPY;

    }
    else if(s.compare("make_editor") == 0){
        m_tag = MemberAction_MAKE_EDITOR;

    }
    else if(s.compare("make_owner") == 0){
        m_tag = MemberAction_MAKE_OWNER;

    }
    else if(s.compare("make_viewer") == 0){
        m_tag = MemberAction_MAKE_VIEWER;

    }
    else if(s.compare("make_viewer_no_comment") == 0){
        m_tag = MemberAction_MAKE_VIEWER_NO_COMMENT;

    }
    else if(s.compare("remove") == 0){
        m_tag = MemberAction_REMOVE;

    }
    else if(s.compare("other") == 0){
        m_tag = MemberAction_OTHER;

    }
}

QString MemberAction::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MemberAction");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MemberAction>  MemberAction::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MemberAction> rv = std::unique_ptr<MemberAction>(new MemberAction);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
