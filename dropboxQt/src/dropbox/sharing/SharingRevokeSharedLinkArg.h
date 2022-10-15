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
    class RevokeSharedLinkArg{
        /**
            field: url: URL of the shared link.
        */

    public:
        RevokeSharedLinkArg(){};

        RevokeSharedLinkArg(const QString& arg){ m_url = arg; };
        virtual ~RevokeSharedLinkArg(){};

    public:
            /**
                URL of the shared link.
            */
        QString url()const{return m_url;};
        RevokeSharedLinkArg& setUrl(const QString& arg){m_url=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeSharedLinkArg>  create(const QByteArray& data);
            static std::unique_ptr<RevokeSharedLinkArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                URL of the shared link.
            */
        QString m_url;

    };//RevokeSharedLinkArg

}//sharing
}//dropboxQt
