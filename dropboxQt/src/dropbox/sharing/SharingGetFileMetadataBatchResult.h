/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingGetFileMetadataIndividualResult.h"

namespace dropboxQt{
namespace sharing{
    class GetFileMetadataBatchResult{
        /**
            Per file results of :meth:`get_file_metadata_batch`

            field: file: This is the input file identifier corresponding to one
                of ``GetFileMetadataBatchArg.files``.
            field: result: The result for this particular file
        */

    public:
        GetFileMetadataBatchResult(){};

        GetFileMetadataBatchResult(const QString& arg){ m_file = arg; };
        virtual ~GetFileMetadataBatchResult(){};

    public:
            /**
                This is the input file identifier corresponding to one of
                ``GetFileMetadataBatchArg.files``.
            */
        QString file()const{return m_file;};

            /**
                The result for this particular file
            */
        const GetFileMetadataIndividualResult& result()const{return m_result;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetFileMetadataBatchResult>  create(const QByteArray& data);
            static std::unique_ptr<GetFileMetadataBatchResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                This is the input file identifier corresponding to one of
                ``GetFileMetadataBatchArg.files``.
            */
        QString m_file;

            /**
                The result for this particular file
            */
        GetFileMetadataIndividualResult m_result;

    };//GetFileMetadataBatchResult

}//sharing
}//dropboxQt
