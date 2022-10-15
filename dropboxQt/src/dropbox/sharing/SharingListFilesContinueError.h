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

namespace dropboxQt{
namespace sharing{
    class ListFilesContinueError{
        /**
            Error results for :meth:`list_received_files_continue`.

            field: user_error: User account had a problem.
            field: invalid_cursor: ``ListFilesContinueArg.cursor`` is invalid.
        */
    public:
        enum Tag{

        /*User account had a problem.*/
        ListFilesContinueError_USER_ERROR,
        /*:field:`ListFilesContinueArg.cursor` is invalid.*/
        ListFilesContinueError_INVALID_CURSOR,
        /*None*/
        ListFilesContinueError_OTHER
        };

        ListFilesContinueError(){}
        ListFilesContinueError(Tag v):m_tag(v){}
        virtual ~ListFilesContinueError(){}

        Tag tag()const{return m_tag;}
        ///User account had a problem.
        const SharingUserError& getUserError()const{API_CHECK_STATE((ListFilesContinueError_USER_ERROR == m_tag), "expected tag: ListFilesContinueError_USER_ERROR", m_tag);return m_user_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFilesContinueError>  create(const QByteArray& data);
            static std::unique_ptr<ListFilesContinueError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingUserError m_user_error;
    };//ListFilesContinueError

}//sharing
}//dropboxQt
