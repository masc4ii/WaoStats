/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingTransferFolderError.h"

namespace dropboxQt{

namespace sharing{
///TransferFolderError

TransferFolderError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void TransferFolderError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case TransferFolderError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case TransferFolderError_INVALID_DROPBOX_ID:{
            if(!name.isEmpty())
                js[name] = QString("invalid_dropbox_id");
        }break;
        case TransferFolderError_NEW_OWNER_NOT_A_MEMBER:{
            if(!name.isEmpty())
                js[name] = QString("new_owner_not_a_member");
        }break;
        case TransferFolderError_NEW_OWNER_UNMOUNTED:{
            if(!name.isEmpty())
                js[name] = QString("new_owner_unmounted");
        }break;
        case TransferFolderError_NEW_OWNER_EMAIL_UNVERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("new_owner_email_unverified");
        }break;
        case TransferFolderError_TEAM_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("team_folder");
        }break;
        case TransferFolderError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case TransferFolderError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void TransferFolderError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = TransferFolderError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("invalid_dropbox_id") == 0){
        m_tag = TransferFolderError_INVALID_DROPBOX_ID;

    }
    else if(s.compare("new_owner_not_a_member") == 0){
        m_tag = TransferFolderError_NEW_OWNER_NOT_A_MEMBER;

    }
    else if(s.compare("new_owner_unmounted") == 0){
        m_tag = TransferFolderError_NEW_OWNER_UNMOUNTED;

    }
    else if(s.compare("new_owner_email_unverified") == 0){
        m_tag = TransferFolderError_NEW_OWNER_EMAIL_UNVERIFIED;

    }
    else if(s.compare("team_folder") == 0){
        m_tag = TransferFolderError_TEAM_FOLDER;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = TransferFolderError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = TransferFolderError_OTHER;

    }
}

QString TransferFolderError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "TransferFolderError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<TransferFolderError>  TransferFolderError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<TransferFolderError> rv = std::unique_ptr<TransferFolderError>(new TransferFolderError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
