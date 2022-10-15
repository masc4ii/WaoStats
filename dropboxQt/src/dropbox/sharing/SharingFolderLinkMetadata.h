/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedLinkMetadata.h"

namespace dropboxQt{
namespace sharing{
    class FolderLinkMetadata : public SharedLinkMetadata{
        /**
            The metadata of a folder shared link
        */

    public:
        FolderLinkMetadata(){};

        virtual ~FolderLinkMetadata(){};

    public:
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FolderLinkMetadata>  create(const QByteArray& data);
            static std::unique_ptr<FolderLinkMetadata>  create(const QJsonObject& js);
        };



    protected:
    };//FolderLinkMetadata

}//sharing
}//dropboxQt
