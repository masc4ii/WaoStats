/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesMediaMetadata.h"

namespace dropboxQt{
namespace files{
    class PhotoMetadata : public MediaMetadata{
        /**
            Metadata for a photo.
        */

    public:
        PhotoMetadata(){};

        virtual ~PhotoMetadata(){};

    public:
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PhotoMetadata>  create(const QByteArray& data);
            static std::unique_ptr<PhotoMetadata>  create(const QJsonObject& js);
        };



    protected:
    };//PhotoMetadata

}//files
}//dropboxQt
