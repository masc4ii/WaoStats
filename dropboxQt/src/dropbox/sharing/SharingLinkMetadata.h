/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingVisibility.h"

namespace dropboxQt{
namespace sharing{
    class LinkMetadata{
        /**
            Metadata for a shared link. This can be either a
            :class:`PathLinkMetadata` or :class:`CollectionLinkMetadata`.

            field: url: URL of the shared link.
            field: visibility: Who can access the link.
            field: expires: Expiration time, if set. By default the link won't
                expire.
        */

    public:
        LinkMetadata(){};

        LinkMetadata(const QString& arg){ m_url = arg; };
        virtual ~LinkMetadata(){};

    public:
            /**
                URL of the shared link.
            */
        QString url()const{return m_url;};
        LinkMetadata& setUrl(const QString& arg){m_url=arg;return *this;};

            /**
                Who can access the link.
            */
        const Visibility& visibility()const{return m_visibility;};
        LinkMetadata& setVisibility(const Visibility& arg){m_visibility=arg;return *this;};

            /**
                Expiration time, if set. By default the link won't expire.
            */
        QDateTime expires()const{return m_expires;};
        LinkMetadata& setExpires(const QDateTime& arg){m_expires=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<LinkMetadata>  create(const QByteArray& data);
            static std::unique_ptr<LinkMetadata>  create(const QJsonObject& js);
        };



    protected:
            /**
                URL of the shared link.
            */
        QString m_url;

            /**
                Who can access the link.
            */
        Visibility m_visibility;

            /**
                Expiration time, if set. By default the link won't expire.
            */
        QDateTime m_expires;

    };//LinkMetadata

}//sharing
}//dropboxQt
