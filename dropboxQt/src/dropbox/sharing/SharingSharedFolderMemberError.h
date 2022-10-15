/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMemberAccessLevelResult.h"

namespace dropboxQt{
namespace sharing{
    class SharedFolderMemberError{
        /**
            field: invalid_dropbox_id: The target dropbox_id is invalid.
            field: not_a_member: The target dropbox_id is not a member of the
                shared folder.
            field: no_explicit_access: The target member only has inherited
                access to the shared folder.
        */
    public:
        enum Tag{

        /*The target dropbox_id is invalid.*/
        SharedFolderMemberError_INVALID_DROPBOX_ID,
        /*The target dropbox_id is not a member of the shared folder.*/
        SharedFolderMemberError_NOT_A_MEMBER,
        /*The target member only has inherited access to the shared folder.*/
        SharedFolderMemberError_NO_EXPLICIT_ACCESS,
        /*None*/
        SharedFolderMemberError_OTHER
        };

        SharedFolderMemberError(){}
        SharedFolderMemberError(Tag v):m_tag(v){}
        virtual ~SharedFolderMemberError(){}

        Tag tag()const{return m_tag;}
        ///The target member only has inherited access to the shared folder.
        const MemberAccessLevelResult& getNoExplicitAccess()const{API_CHECK_STATE((SharedFolderMemberError_NO_EXPLICIT_ACCESS == m_tag), "expected tag: SharedFolderMemberError_NO_EXPLICIT_ACCESS", m_tag);return m_no_explicit_access;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderMemberError>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderMemberError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        MemberAccessLevelResult m_no_explicit_access;
    };//SharedFolderMemberError

}//sharing
}//dropboxQt
