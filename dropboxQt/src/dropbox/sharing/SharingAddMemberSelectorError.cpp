/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAddMemberSelectorError.h"

namespace dropboxQt{

namespace sharing{
///AddMemberSelectorError

AddMemberSelectorError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AddMemberSelectorError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AddMemberSelectorError_AUTOMATIC_GROUP:{
            if(!name.isEmpty())
                js[name] = QString("automatic_group");
        }break;
        case AddMemberSelectorError_INVALID_DROPBOX_ID:{
            if(!name.isEmpty())
                js[name] = QString("invalid_dropbox_id");
            if(!m_invalid_dropbox_id.isEmpty())
                js["invalid_dropbox_id"] = QString(m_invalid_dropbox_id);
        }break;
        case AddMemberSelectorError_INVALID_EMAIL:{
            if(!name.isEmpty())
                js[name] = QString("invalid_email");
            if(!m_invalid_email.isEmpty())
                js["invalid_email"] = QString(m_invalid_email);
        }break;
        case AddMemberSelectorError_UNVERIFIED_DROPBOX_ID:{
            if(!name.isEmpty())
                js[name] = QString("unverified_dropbox_id");
            if(!m_unverified_dropbox_id.isEmpty())
                js["unverified_dropbox_id"] = QString(m_unverified_dropbox_id);
        }break;
        case AddMemberSelectorError_GROUP_DELETED:{
            if(!name.isEmpty())
                js[name] = QString("group_deleted");
        }break;
        case AddMemberSelectorError_GROUP_NOT_ON_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("group_not_on_team");
        }break;
        case AddMemberSelectorError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void AddMemberSelectorError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("automatic_group") == 0){
        m_tag = AddMemberSelectorError_AUTOMATIC_GROUP;

    }
    else if(s.compare("invalid_dropbox_id") == 0){
        m_tag = AddMemberSelectorError_INVALID_DROPBOX_ID;
        m_invalid_dropbox_id = js["invalid_dropbox_id"].toString();
    }
    else if(s.compare("invalid_email") == 0){
        m_tag = AddMemberSelectorError_INVALID_EMAIL;
        m_invalid_email = js["invalid_email"].toString();
    }
    else if(s.compare("unverified_dropbox_id") == 0){
        m_tag = AddMemberSelectorError_UNVERIFIED_DROPBOX_ID;
        m_unverified_dropbox_id = js["unverified_dropbox_id"].toString();
    }
    else if(s.compare("group_deleted") == 0){
        m_tag = AddMemberSelectorError_GROUP_DELETED;

    }
    else if(s.compare("group_not_on_team") == 0){
        m_tag = AddMemberSelectorError_GROUP_NOT_ON_TEAM;

    }
    else if(s.compare("other") == 0){
        m_tag = AddMemberSelectorError_OTHER;

    }
}

QString AddMemberSelectorError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AddMemberSelectorError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AddMemberSelectorError>  AddMemberSelectorError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AddMemberSelectorError> rv = std::unique_ptr<AddMemberSelectorError>(new AddMemberSelectorError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
