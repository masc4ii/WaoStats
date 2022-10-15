/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingRequestedVisibility.h"

namespace dropboxQt{
namespace sharing{
    class SharedLinkSettings{
        /**
            field: requested_visibility: The requested access for this shared
                link.
            field: link_password: If ``requested_visibility`` is
                ``RequestedVisibility.password`` this is needed to specify the
                password to access the link.
            field: expires: Expiration time of the shared link. By default the
                link won't expire.
        */

    public:
        SharedLinkSettings(){};

        SharedLinkSettings(const RequestedVisibility& arg){ m_requested_visibility = arg; };
        virtual ~SharedLinkSettings(){};

    public:
            /**
                The requested access for this shared link.
            */
        const RequestedVisibility& requestedVisibility()const{return m_requested_visibility;};
        SharedLinkSettings& setRequestedvisibility(const RequestedVisibility& arg){m_requested_visibility=arg;return *this;};

            /**
                If ``requested_visibility`` is ``RequestedVisibility.password``
                this is needed to specify the password to access the link.
            */
        QString linkPassword()const{return m_link_password;};
        SharedLinkSettings& setLinkpassword(const QString& arg){m_link_password=arg;return *this;};

            /**
                Expiration time of the shared link. By default the link won't
                expire.
            */
        QDateTime expires()const{return m_expires;};
        SharedLinkSettings& setExpires(const QDateTime& arg){m_expires=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedLinkSettings>  create(const QByteArray& data);
            static std::unique_ptr<SharedLinkSettings>  create(const QJsonObject& js);
        };



    protected:
            /**
                The requested access for this shared link.
            */
        RequestedVisibility m_requested_visibility;

            /**
                If ``requested_visibility`` is ``RequestedVisibility.password``
                this is needed to specify the password to access the link.
            */
        QString m_link_password;

            /**
                Expiration time of the shared link. By default the link won't
                expire.
            */
        QDateTime m_expires;

    };//SharedLinkSettings

}//sharing
}//dropboxQt
