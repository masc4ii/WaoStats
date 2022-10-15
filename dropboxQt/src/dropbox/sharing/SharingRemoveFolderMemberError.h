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
#include "dropbox/sharing/SharingSharedFolderMemberError.h"

namespace dropboxQt{
namespace sharing{
    class RemoveFolderMemberError{
        /**
            field: folder_owner: The target user is the owner of the shared
                folder. You can't remove this user until ownership has been
                transferred to another member.
            field: group_access: The target user has access to the shared folder
                via a group.
            field: team_folder: This action cannot be performed on a team shared
                folder.
            field: no_permission: The current user does not have permission to
                perform this action.
        */
    public:
        enum Tag{

        /*None*/
        RemoveFolderMemberError_ACCESS_ERROR,
        /*None*/
        RemoveFolderMemberError_MEMBER_ERROR,
        /*The target user is the owner of the shared folder. You can't remove this user until ownership has been transferred to another member.*/
        RemoveFolderMemberError_FOLDER_OWNER,
        /*The target user has access to the shared folder via a group.*/
        RemoveFolderMemberError_GROUP_ACCESS,
        /*This action cannot be performed on a team shared folder.*/
        RemoveFolderMemberError_TEAM_FOLDER,
        /*The current user does not have permission to perform this action.*/
        RemoveFolderMemberError_NO_PERMISSION,
        /*None*/
        RemoveFolderMemberError_OTHER
        };

        RemoveFolderMemberError(){}
        RemoveFolderMemberError(Tag v):m_tag(v){}
        virtual ~RemoveFolderMemberError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharedFolderAccessError& getAccessError()const{API_CHECK_STATE((RemoveFolderMemberError_ACCESS_ERROR == m_tag), "expected tag: RemoveFolderMemberError_ACCESS_ERROR", m_tag);return m_access_error;};

        ///None
        const SharedFolderMemberError& getMemberError()const{API_CHECK_STATE((RemoveFolderMemberError_MEMBER_ERROR == m_tag), "expected tag: RemoveFolderMemberError_MEMBER_ERROR", m_tag);return m_member_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemoveFolderMemberError>  create(const QByteArray& data);
            static std::unique_ptr<RemoveFolderMemberError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderAccessError m_access_error;
        SharedFolderMemberError m_member_error;
    };//RemoveFolderMemberError

}//sharing
}//dropboxQt
