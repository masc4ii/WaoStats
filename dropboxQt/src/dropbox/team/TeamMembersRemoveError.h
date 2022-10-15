/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMembersDeactivateError.h"

namespace dropboxQt{
namespace team{
    class MembersRemoveError{
        /**
            field: remove_last_admin: The user is the last admin of the team, so
                it cannot be removed from it.
            field: removed_and_transfer_dest_should_differ: Expected removed
                user and transfer_dest user to be different
            field: removed_and_transfer_admin_should_differ: Expected removed
                user and transfer_admin user to be different.
            field: transfer_dest_user_not_found: No matching user found for the
                argument transfer_dest_id.
            field: transfer_dest_user_not_in_team: The provided transfer_dest_id
                does not exist on this team.
            field: transfer_admin_user_not_found: No matching user found for the
                argument transfer_admin_id.
            field: transfer_admin_user_not_in_team: The provided
                transfer_admin_id does not exist on this team.
            field: unspecified_transfer_admin_id: The transfer_admin_id argument
                must be provided when file transfer is requested.
            field: transfer_admin_is_not_admin: Specified transfer_admin user is
                not a team admin.
            field: cannot_keep_account_and_transfer: Cannot keep account and
                transfer the data to another user at the same time.
            field: cannot_keep_account_and_delete_data: Cannot keep account and
                delete the data at the same time.
            field: email_address_too_long_to_be_disabled: The email address of
                the user is too long to be disabled.
        */
    public:
        enum Tag{

        /*No matching user found. The provided team_member_id, email, or external_id does not exist on this team.*/
        UserSelectorError_USER_NOT_FOUND,
        /*The user is not a member of the team.*/
        MembersDeactivateError_USER_NOT_IN_TEAM,
        /*None*/
        MembersDeactivateError_OTHER,
        /*The user is the last admin of the team, so it cannot be removed from it.*/
        MembersRemoveError_REMOVE_LAST_ADMIN,
        /*Expected removed user and transfer_dest user to be different*/
        MembersRemoveError_REMOVED_AND_TRANSFER_DEST_SHOULD_DIFFER,
        /*Expected removed user and transfer_admin user to be different.*/
        MembersRemoveError_REMOVED_AND_TRANSFER_ADMIN_SHOULD_DIFFER,
        /*No matching user found for the argument transfer_dest_id.*/
        MembersRemoveError_TRANSFER_DEST_USER_NOT_FOUND,
        /*The provided transfer_dest_id does not exist on this team.*/
        MembersRemoveError_TRANSFER_DEST_USER_NOT_IN_TEAM,
        /*No matching user found for the argument transfer_admin_id.*/
        MembersRemoveError_TRANSFER_ADMIN_USER_NOT_FOUND,
        /*The provided transfer_admin_id does not exist on this team.*/
        MembersRemoveError_TRANSFER_ADMIN_USER_NOT_IN_TEAM,
        /*The transfer_admin_id argument must be provided when file transfer is requested.*/
        MembersRemoveError_UNSPECIFIED_TRANSFER_ADMIN_ID,
        /*Specified transfer_admin user is not a team admin.*/
        MembersRemoveError_TRANSFER_ADMIN_IS_NOT_ADMIN,
        /*Cannot keep account and transfer the data to another user at the same time.*/
        MembersRemoveError_CANNOT_KEEP_ACCOUNT_AND_TRANSFER,
        /*Cannot keep account and delete the data at the same time.*/
        MembersRemoveError_CANNOT_KEEP_ACCOUNT_AND_DELETE_DATA,
        /*The email address of the user is too long to be disabled.*/
        MembersRemoveError_EMAIL_ADDRESS_TOO_LONG_TO_BE_DISABLED
        };

        MembersRemoveError(){}
        MembersRemoveError(Tag v):m_tag(v){}
        virtual ~MembersRemoveError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersRemoveError>  create(const QByteArray& data);
            static std::unique_ptr<MembersRemoveError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MembersRemoveError

}//team
}//dropboxQt
