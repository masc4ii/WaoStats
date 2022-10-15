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
    class PathLinkMetadata : public LinkMetadata{
        /**
            Metadata for a path-based shared link.

            field: path: Path in user's Dropbox.
        */

    public:
        PathLinkMetadata(){};

        PathLinkMetadata(const QString& arg){ m_path = arg; };
        virtual ~PathLinkMetadata(){};

    public:
            /**
                Path in user's Dropbox.
            */
        QString path()const{return m_path;};
        PathLinkMetadata& setPath(const QString& arg){m_path=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PathLinkMetadata>  create(const QByteArray& data);
            static std::unique_ptr<PathLinkMetadata>  create(const QJsonObject& js);
        };



    protected:
            /**
                Path in user's Dropbox.
            */
        QString m_path;

    };//PathLinkMetadata

}//sharing
}//dropboxQt
