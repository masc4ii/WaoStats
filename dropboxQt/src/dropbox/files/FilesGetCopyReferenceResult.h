/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesMetadata.h"

namespace dropboxQt{
namespace files{
    class GetCopyReferenceResult{
        /**
            field: metadata: Metadata of the file or folder.
            field: copy_reference: A copy reference to the file or folder.
            field: expires: The expiration date of the copy reference. This
                value is currently set to be far enough in the future so that
                expiration is effectively not an issue.
        */

    public:
        GetCopyReferenceResult(){};

        GetCopyReferenceResult(const Metadata& arg){ m_metadata = arg; };
        virtual ~GetCopyReferenceResult(){};

    public:
            /**
                Metadata of the file or folder.
            */
        const Metadata& metadata()const{return m_metadata;};

            /**
                A copy reference to the file or folder.
            */
        QString copyReference()const{return m_copy_reference;};

            /**
                The expiration date of the copy reference. This value is
                currently set to be far enough in the future so that expiration
                is effectively not an issue.
            */
        QDateTime expires()const{return m_expires;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetCopyReferenceResult>  create(const QByteArray& data);
            static std::unique_ptr<GetCopyReferenceResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Metadata of the file or folder.
            */
        Metadata m_metadata;

            /**
                A copy reference to the file or folder.
            */
        QString m_copy_reference;

            /**
                The expiration date of the copy reference. This value is
                currently set to be far enough in the future so that expiration
                is effectively not an issue.
            */
        QDateTime m_expires;

    };//GetCopyReferenceResult

}//files
}//dropboxQt
