/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class GetSharedLinkMetadataArg{
        /**
            field: url: URL of the shared link.
            field: path: If the shared link is to a folder, this parameter can
                be used to retrieve the metadata for a specific file or
                sub-folder in this folder. A relative path should be used.
            field: link_password: If the shared link has a password, this
                parameter can be used.
        */

    public:
        GetSharedLinkMetadataArg(){};

        GetSharedLinkMetadataArg(const QString& arg){ m_url = arg; };
        virtual ~GetSharedLinkMetadataArg(){};

    public:
            /**
                URL of the shared link.
            */
        QString url()const{return m_url;};
        GetSharedLinkMetadataArg& setUrl(const QString& arg){m_url=arg;return *this;};

            /**
                If the shared link is to a folder, this parameter can be used to
                retrieve the metadata for a specific file or sub-folder in this
                folder. A relative path should be used.
            */
        QString path()const{return m_path;};
        GetSharedLinkMetadataArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                If the shared link has a password, this parameter can be used.
            */
        QString linkPassword()const{return m_link_password;};
        GetSharedLinkMetadataArg& setLinkpassword(const QString& arg){m_link_password=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetSharedLinkMetadataArg>  create(const QByteArray& data);
            static std::unique_ptr<GetSharedLinkMetadataArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                URL of the shared link.
            */
        QString m_url;

            /**
                If the shared link is to a folder, this parameter can be used to
                retrieve the metadata for a specific file or sub-folder in this
                folder. A relative path should be used.
            */
        QString m_path;

            /**
                If the shared link has a password, this parameter can be used.
            */
        QString m_link_password;

    };//GetSharedLinkMetadataArg

}//sharing
}//dropboxQt
