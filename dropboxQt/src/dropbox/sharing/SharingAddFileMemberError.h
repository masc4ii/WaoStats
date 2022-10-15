/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharingUserError.h"
#include "dropbox/sharing/SharingSharingFileAccessError.h"

namespace dropboxQt{
namespace sharing{
    class AddFileMemberError{
        /**
            Errors for :meth:`add_file_member`.

            field: rate_limit: The user has reached the rate limit for
                invitations.
            field: invalid_comment: The custom message did not pass comment
                permissions checks.
        */
    public:
        enum Tag{

        /*None*/
        AddFileMemberError_USER_ERROR,
        /*None*/
        AddFileMemberError_ACCESS_ERROR,
        /*The user has reached the rate limit for invitations.*/
        AddFileMemberError_RATE_LIMIT,
        /*The custom message did not pass comment permissions checks.*/
        AddFileMemberError_INVALID_COMMENT,
        /*None*/
        AddFileMemberError_OTHER
        };

        AddFileMemberError(){}
        AddFileMemberError(Tag v):m_tag(v){}
        virtual ~AddFileMemberError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharingUserError& getUserError()const{API_CHECK_STATE((AddFileMemberError_USER_ERROR == m_tag), "expected tag: AddFileMemberError_USER_ERROR", m_tag);return m_user_error;};

        ///None
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((AddFileMemberError_ACCESS_ERROR == m_tag), "expected tag: AddFileMemberError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AddFileMemberError>  create(const QByteArray& data);
            static std::unique_ptr<AddFileMemberError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingUserError m_user_error;
        SharingFileAccessError m_access_error;
    };//AddFileMemberError

}//sharing
}//dropboxQt
