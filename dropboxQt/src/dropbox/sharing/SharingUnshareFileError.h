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
    class UnshareFileError{
        /**
            Error result for :meth:`unshare_file`.
        */
    public:
        enum Tag{

        /*None*/
        UnshareFileError_USER_ERROR,
        /*None*/
        UnshareFileError_ACCESS_ERROR,
        /*None*/
        UnshareFileError_OTHER
        };

        UnshareFileError(){}
        UnshareFileError(Tag v):m_tag(v){}
        virtual ~UnshareFileError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharingUserError& getUserError()const{API_CHECK_STATE((UnshareFileError_USER_ERROR == m_tag), "expected tag: UnshareFileError_USER_ERROR", m_tag);return m_user_error;};

        ///None
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((UnshareFileError_ACCESS_ERROR == m_tag), "expected tag: UnshareFileError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UnshareFileError>  create(const QByteArray& data);
            static std::unique_ptr<UnshareFileError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingUserError m_user_error;
        SharingFileAccessError m_access_error;
    };//UnshareFileError

}//sharing
}//dropboxQt
