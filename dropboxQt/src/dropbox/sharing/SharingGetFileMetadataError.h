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
    class GetFileMetadataError{
        /**
            Error result for :meth:`get_file_metadata`.
        */
    public:
        enum Tag{

        /*None*/
        GetFileMetadataError_USER_ERROR,
        /*None*/
        GetFileMetadataError_ACCESS_ERROR,
        /*None*/
        GetFileMetadataError_OTHER
        };

        GetFileMetadataError(){}
        GetFileMetadataError(Tag v):m_tag(v){}
        virtual ~GetFileMetadataError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharingUserError& getUserError()const{API_CHECK_STATE((GetFileMetadataError_USER_ERROR == m_tag), "expected tag: GetFileMetadataError_USER_ERROR", m_tag);return m_user_error;};

        ///None
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((GetFileMetadataError_ACCESS_ERROR == m_tag), "expected tag: GetFileMetadataError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetFileMetadataError>  create(const QByteArray& data);
            static std::unique_ptr<GetFileMetadataError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingUserError m_user_error;
        SharingFileAccessError m_access_error;
    };//GetFileMetadataError

}//sharing
}//dropboxQt
