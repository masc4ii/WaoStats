/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersRemoveError.h"

namespace dropboxQt{

namespace team{
///MembersRemoveError

MembersRemoveError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersRemoveError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UserSelectorError_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("user_not_found");
        }break;
        case MembersDeactivateError_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_not_in_team");
        }break;
        case MembersDeactivateError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case MembersRemoveError_REMOVE_LAST_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("remove_last_admin");
        }break;
        case MembersRemoveError_REMOVED_AND_TRANSFER_DEST_SHOULD_DIFFER:{
            if(!name.isEmpty())
                js[name] = QString("removed_and_transfer_dest_should_differ");
        }break;
        case MembersRemoveError_REMOVED_AND_TRANSFER_ADMIN_SHOULD_DIFFER:{
            if(!name.isEmpty())
                js[name] = QString("removed_and_transfer_admin_should_differ");
        }break;
        case MembersRemoveError_TRANSFER_DEST_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("transfer_dest_user_not_found");
        }break;
        case MembersRemoveError_TRANSFER_DEST_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("transfer_dest_user_not_in_team");
        }break;
        case MembersRemoveError_TRANSFER_ADMIN_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("transfer_admin_user_not_found");
        }break;
        case MembersRemoveError_TRANSFER_ADMIN_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("transfer_admin_user_not_in_team");
        }break;
        case MembersRemoveError_UNSPECIFIED_TRANSFER_ADMIN_ID:{
            if(!name.isEmpty())
                js[name] = QString("unspecified_transfer_admin_id");
        }break;
        case MembersRemoveError_TRANSFER_ADMIN_IS_NOT_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("transfer_admin_is_not_admin");
        }break;
        case MembersRemoveError_CANNOT_KEEP_ACCOUNT_AND_TRANSFER:{
            if(!name.isEmpty())
                js[name] = QString("cannot_keep_account_and_transfer");
        }break;
        case MembersRemoveError_CANNOT_KEEP_ACCOUNT_AND_DELETE_DATA:{
            if(!name.isEmpty())
                js[name] = QString("cannot_keep_account_and_delete_data");
        }break;
        case MembersRemoveError_EMAIL_ADDRESS_TOO_LONG_TO_BE_DISABLED:{
            if(!name.isEmpty())
                js[name] = QString("email_address_too_long_to_be_disabled");
        }break;
    }//switch
}

void MembersRemoveError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_not_found") == 0){
        m_tag = UserSelectorError_USER_NOT_FOUND;

    }
    if(s.compare("user_not_in_team") == 0){
        m_tag = MembersDeactivateError_USER_NOT_IN_TEAM;

    }
    else if(s.compare("other") == 0){
        m_tag = MembersDeactivateError_OTHER;

    }
    if(s.compare("remove_last_admin") == 0){
        m_tag = MembersRemoveError_REMOVE_LAST_ADMIN;

    }
    else if(s.compare("removed_and_transfer_dest_should_differ") == 0){
        m_tag = MembersRemoveError_REMOVED_AND_TRANSFER_DEST_SHOULD_DIFFER;

    }
    else if(s.compare("removed_and_transfer_admin_should_differ") == 0){
        m_tag = MembersRemoveError_REMOVED_AND_TRANSFER_ADMIN_SHOULD_DIFFER;

    }
    else if(s.compare("transfer_dest_user_not_found") == 0){
        m_tag = MembersRemoveError_TRANSFER_DEST_USER_NOT_FOUND;

    }
    else if(s.compare("transfer_dest_user_not_in_team") == 0){
        m_tag = MembersRemoveError_TRANSFER_DEST_USER_NOT_IN_TEAM;

    }
    else if(s.compare("transfer_admin_user_not_found") == 0){
        m_tag = MembersRemoveError_TRANSFER_ADMIN_USER_NOT_FOUND;

    }
    else if(s.compare("transfer_admin_user_not_in_team") == 0){
        m_tag = MembersRemoveError_TRANSFER_ADMIN_USER_NOT_IN_TEAM;

    }
    else if(s.compare("unspecified_transfer_admin_id") == 0){
        m_tag = MembersRemoveError_UNSPECIFIED_TRANSFER_ADMIN_ID;

    }
    else if(s.compare("transfer_admin_is_not_admin") == 0){
        m_tag = MembersRemoveError_TRANSFER_ADMIN_IS_NOT_ADMIN;

    }
    else if(s.compare("cannot_keep_account_and_transfer") == 0){
        m_tag = MembersRemoveError_CANNOT_KEEP_ACCOUNT_AND_TRANSFER;

    }
    else if(s.compare("cannot_keep_account_and_delete_data") == 0){
        m_tag = MembersRemoveError_CANNOT_KEEP_ACCOUNT_AND_DELETE_DATA;

    }
    else if(s.compare("email_address_too_long_to_be_disabled") == 0){
        m_tag = MembersRemoveError_EMAIL_ADDRESS_TOO_LONG_TO_BE_DISABLED;

    }
}

QString MembersRemoveError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersRemoveError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersRemoveError>  MembersRemoveError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersRemoveError> rv = std::unique_ptr<MembersRemoveError>(new MembersRemoveError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
