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
    class SaveCopyReferenceResult{
        /**
            field: metadata: The metadata of the saved file or folder in the
                user's Dropbox.
        */

    public:
        SaveCopyReferenceResult(){};

        SaveCopyReferenceResult(const Metadata& arg){ m_metadata = arg; };
        virtual ~SaveCopyReferenceResult(){};

    public:
            /**
                The metadata of the saved file or folder in the user's Dropbox.
            */
        const Metadata& metadata()const{return m_metadata;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SaveCopyReferenceResult>  create(const QByteArray& data);
            static std::unique_ptr<SaveCopyReferenceResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                The metadata of the saved file or folder in the user's Dropbox.
            */
        Metadata m_metadata;

    };//SaveCopyReferenceResult

}//files
}//dropboxQt
