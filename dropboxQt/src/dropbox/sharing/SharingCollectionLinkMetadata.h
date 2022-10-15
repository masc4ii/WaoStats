/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingLinkMetadata.h"

namespace dropboxQt{
namespace sharing{
    class CollectionLinkMetadata : public LinkMetadata{
        /**
            Metadata for a collection-based shared link.
        */

    public:
        CollectionLinkMetadata(){};

        virtual ~CollectionLinkMetadata(){};

    public:
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<CollectionLinkMetadata>  create(const QByteArray& data);
            static std::unique_ptr<CollectionLinkMetadata>  create(const QJsonObject& js);
        };



    protected:
    };//CollectionLinkMetadata

}//sharing
}//dropboxQt
