/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesFileMetadata.h"

namespace dropboxQt{
namespace files{
    class GetTemporaryLinkResult{
        /**
            field: metadata: Metadata of the file.
            field: link: The temporary link which can be used to stream content
                the file.
        */

    public:
        GetTemporaryLinkResult(){};

        GetTemporaryLinkResult(const FileMetadata& arg){ m_metadata = arg; };
        virtual ~GetTemporaryLinkResult(){};

    public:
            /**
                Metadata of the file.
            */
        const FileMetadata& metadata()const{return m_metadata;};

            /**
                The temporary link which can be used to stream content the file.
            */
        QString link()const{return m_link;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetTemporaryLinkResult>  create(const QByteArray& data);
            static std::unique_ptr<GetTemporaryLinkResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Metadata of the file.
            */
        FileMetadata m_metadata;

            /**
                The temporary link which can be used to stream content the file.
            */
        QString m_link;

    };//GetTemporaryLinkResult

}//files
}//dropboxQt
