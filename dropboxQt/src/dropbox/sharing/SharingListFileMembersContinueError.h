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
    class ListFileMembersContinueError{
        /**
            Error for :meth:`list_file_members_continue`.

            field: invalid_cursor: ``ListFileMembersContinueArg.cursor`` is
                invalid.
        */
    public:
        enum Tag{

        /*None*/
        ListFileMembersContinueError_USER_ERROR,
        /*None*/
        ListFileMembersContinueError_ACCESS_ERROR,
        /*:field:`ListFileMembersContinueArg.cursor` is invalid.*/
        ListFileMembersContinueError_INVALID_CURSOR,
        /*None*/
        ListFileMembersContinueError_OTHER
        };

        ListFileMembersContinueError(){}
        ListFileMembersContinueError(Tag v):m_tag(v){}
        virtual ~ListFileMembersContinueError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharingUserError& getUserError()const{API_CHECK_STATE((ListFileMembersContinueError_USER_ERROR == m_tag), "expected tag: ListFileMembersContinueError_USER_ERROR", m_tag);return m_user_error;};

        ///None
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((ListFileMembersContinueError_ACCESS_ERROR == m_tag), "expected tag: ListFileMembersContinueError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFileMembersContinueError>  create(const QByteArray& data);
            static std::unique_ptr<ListFileMembersContinueError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingUserError m_user_error;
        SharingFileAccessError m_access_error;
    };//ListFileMembersContinueError

}//sharing
}//dropboxQt
