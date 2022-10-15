/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFolderAccessError.h"

namespace dropboxQt{
namespace sharing{
    class TransferFolderError{
        /**
            field: invalid_dropbox_id: ``TransferFolderArg.to_dropbox_id`` is
                invalid.
            field: new_owner_not_a_member: The new designated owner is not
                currently a member of the shared folder.
            field: new_owner_unmounted: The new designated owner has not added
                the folder to their Dropbox.
            field: new_owner_email_unverified: The new designated owner's e-mail
                address is unverified.
            field: team_folder: This action cannot be performed on a team shared
                folder.
            field: no_permission: The current user does not have permission to
                perform this action.
        */
    public:
        enum Tag{

        /*None*/
        TransferFolderError_ACCESS_ERROR,
        /*:field:`TransferFolderArg.to_dropbox_id` is invalid.*/
        TransferFolderError_INVALID_DROPBOX_ID,
        /*The new designated owner is not currently a member of the shared folder.*/
        TransferFolderError_NEW_OWNER_NOT_A_MEMBER,
        /*The new designated owner has not added the folder to their Dropbox.*/
        TransferFolderError_NEW_OWNER_UNMOUNTED,
        /*The new designated owner's e-mail address is unverified.*/
        TransferFolderError_NEW_OWNER_EMAIL_UNVERIFIED,
        /*This action cannot be performed on a team shared folder.*/
        TransferFolderError_TEAM_FOLDER,
        /*The current user does not have permission to perform this action.*/
        TransferFolderError_NO_PERMISSION,
        /*None*/
        TransferFolderError_OTHER
        };

        TransferFolderError(){}
        TransferFolderError(Tag v):m_tag(v){}
        virtual ~TransferFolderError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharedFolderAccessError& getAccessError()const{API_CHECK_STATE((TransferFolderError_ACCESS_ERROR == m_tag), "expected tag: TransferFolderError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TransferFolderError>  create(const QByteArray& data);
            static std::unique_ptr<TransferFolderError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderAccessError m_access_error;
    };//TransferFolderError

}//sharing
}//dropboxQt
