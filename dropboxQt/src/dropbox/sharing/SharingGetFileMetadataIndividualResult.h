/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFileMetadata.h"
#include "dropbox/sharing/SharingSharingFileAccessError.h"

namespace dropboxQt{
namespace sharing{
    class GetFileMetadataIndividualResult{
        /**
            field: metadata: The result for this file if it was successful.
            field: access_error: The result for this file if it was an error.
        */
    public:
        enum Tag{

        /*The result for this file if it was successful.*/
        GetFileMetadataIndividualResult_METADATA,
        /*The result for this file if it was an error.*/
        GetFileMetadataIndividualResult_ACCESS_ERROR,
        /*None*/
        GetFileMetadataIndividualResult_OTHER
        };

        GetFileMetadataIndividualResult(){}
        GetFileMetadataIndividualResult(Tag v):m_tag(v){}
        virtual ~GetFileMetadataIndividualResult(){}

        Tag tag()const{return m_tag;}
        ///The result for this file if it was successful.
        const SharedFileMetadata& getMetadata()const{API_CHECK_STATE((GetFileMetadataIndividualResult_METADATA == m_tag), "expected tag: GetFileMetadataIndividualResult_METADATA", m_tag);return m_metadata;};

        ///The result for this file if it was an error.
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((GetFileMetadataIndividualResult_ACCESS_ERROR == m_tag), "expected tag: GetFileMetadataIndividualResult_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetFileMetadataIndividualResult>  create(const QByteArray& data);
            static std::unique_ptr<GetFileMetadataIndividualResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFileMetadata m_metadata;
        SharingFileAccessError m_access_error;
    };//GetFileMetadataIndividualResult

}//sharing
}//dropboxQt
