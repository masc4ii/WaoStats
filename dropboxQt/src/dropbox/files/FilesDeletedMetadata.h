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
    class DeletedMetadata : public Metadata{
        /**
            Indicates that there used to be a file or folder at this path, but
            it no longer exists.
        */

    public:
        DeletedMetadata(){};

        virtual ~DeletedMetadata(){};

    public:
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<DeletedMetadata>  create(const QByteArray& data);
            static std::unique_ptr<DeletedMetadata>  create(const QJsonObject& js);
        };



    protected:
    };//DeletedMetadata

}//files
}//dropboxQt
