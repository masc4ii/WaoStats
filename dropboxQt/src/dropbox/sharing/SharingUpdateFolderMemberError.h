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
#include "dropbox/sharing/SharingAddFolderMemberError.h"

namespace dropboxQt{
namespace sharing{
    class UpdateFolderMemberError{
        /**
            field: no_explicit_access: If updating the access type required the
                member to be added to the shared folder and there was an error
                when adding the member.
            field: insufficient_plan: The current user's account doesn't support
                this action. An example of this is when downgrading a member
                from editor to viewer. This action can only be performed by
                users that have upgraded to a Pro or Business plan.
            field: no_permission: The current user does not have permission to
                perform this action.
        */
    public:
        enum Tag{

        /*None*/
        UpdateFolderMemberError_ACCESS_ERROR,
        /*None*/
        UpdateFolderMemberError_MEMBER_ERROR,
        /*If updating the access type required the member to be added to the shared folder and there was an error when adding the member.*/
        UpdateFolderMemberError_NO_EXPLICIT_ACCESS,
        /*The current user's account doesn't support this action. An example of this is when downgrading a member from editor to viewer. This action can only be performed by users that have upgraded to a Pro or Business plan.*/
        UpdateFolderMemberError_INSUFFICIENT_PLAN,
        /*The current user does not have permission to perform this action.*/
        UpdateFolderMemberError_NO_PERMISSION,
        /*None*/
        UpdateFolderMemberError_OTHER
        };

        UpdateFolderMemberError(){}
        UpdateFolderMemberError(Tag v):m_tag(v){}
        virtual ~UpdateFolderMemberError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharedFolderAccessError& getAccessError()const{API_CHECK_STATE((UpdateFolderMemberError_ACCESS_ERROR == m_tag), "expected tag: UpdateFolderMemberError_ACCESS_ERROR", m_tag);return m_access_error;};

        ///None
        const SharedFolderMemberError& getMemberError()const{API_CHECK_STATE((UpdateFolderMemberError_MEMBER_ERROR == m_tag), "expected tag: UpdateFolderMemberError_MEMBER_ERROR", m_tag);return m_member_error;};

        ///If updating the access type required the member to be added to the shared folder and there was an error when adding the member.
        const AddFolderMemberError& getNoExplicitAccess()const{API_CHECK_STATE((UpdateFolderMemberError_NO_EXPLICIT_ACCESS == m_tag), "expected tag: UpdateFolderMemberError_NO_EXPLICIT_ACCESS", m_tag);return m_no_explicit_access;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UpdateFolderMemberError>  create(const QByteArray& data);
            static std::unique_ptr<UpdateFolderMemberError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderAccessError m_access_error;
        SharedFolderMemberError m_member_error;
        AddFolderMemberError m_no_explicit_access;
    };//UpdateFolderMemberError

}//sharing
}//dropboxQt
