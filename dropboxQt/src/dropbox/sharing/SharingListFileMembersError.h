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
    class ListFileMembersError{
        /**
            Error for :meth:`list_file_members`.
        */
    public:
        enum Tag{

        /*None*/
        ListFileMembersError_USER_ERROR,
        /*None*/
        ListFileMembersError_ACCESS_ERROR,
        /*None*/
        ListFileMembersError_OTHER
        };

        ListFileMembersError(){}
        ListFileMembersError(Tag v):m_tag(v){}
        virtual ~ListFileMembersError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharingUserError& getUserError()const{API_CHECK_STATE((ListFileMembersError_USER_ERROR == m_tag), "expected tag: ListFileMembersError_USER_ERROR", m_tag);return m_user_error;};

        ///None
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((ListFileMembersError_ACCESS_ERROR == m_tag), "expected tag: ListFileMembersError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFileMembersError>  create(const QByteArray& data);
            static std::unique_ptr<ListFileMembersError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingUserError m_user_error;
        SharingFileAccessError m_access_error;
    };//ListFileMembersError

}//sharing
}//dropboxQt
