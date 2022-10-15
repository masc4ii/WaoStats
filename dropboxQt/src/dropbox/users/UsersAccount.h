/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/users/UsersName.h"

namespace dropboxQt{
namespace users{
    class Account{
        /**
            The amount of detail revealed about an account depends on the user
            being queried and the user making the query.

            field: account_id: The user's unique Dropbox ID.
            field: name: Details of a user's name.
            field: email: The user's e-mail address. Do not rely on this without
                checking the ``email_verified`` field. Even then, it's possible
                that the user has since lost access to their e-mail.
            field: email_verified: Whether the user has verified their e-mail
                address.
            field: profile_photo_url: URL for the photo representing the user,
                if one is set.
            field: disabled: Whether the user has been disabled.
        */

    public:
        Account(){};

        Account(const QString& arg){ m_account_id = arg; };
        virtual ~Account(){};

    public:
            /**
                The user's unique Dropbox ID.
            */
        QString accountId()const{return m_account_id;};
        Account& setAccountid(const QString& arg){m_account_id=arg;return *this;};

            /**
                Details of a user's name.
            */
        const Name& name()const{return m_name;};
        Account& setName(const Name& arg){m_name=arg;return *this;};

            /**
                The user's e-mail address. Do not rely on this without checking
                the ``email_verified`` field. Even then, it's possible that the
                user has since lost access to their e-mail.
            */
        QString email()const{return m_email;};
        Account& setEmail(const QString& arg){m_email=arg;return *this;};

            /**
                Whether the user has verified their e-mail address.
            */
        bool emailVerified()const{return m_email_verified;};
        Account& setEmailverified(const bool& arg){m_email_verified=arg;return *this;};

            /**
                URL for the photo representing the user, if one is set.
            */
        QString profilePhotoUrl()const{return m_profile_photo_url;};
        Account& setProfilephotourl(const QString& arg){m_profile_photo_url=arg;return *this;};

            /**
                Whether the user has been disabled.
            */
        bool disabled()const{return m_disabled;};
        Account& setDisabled(const bool& arg){m_disabled=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<Account>  create(const QByteArray& data);
            static std::unique_ptr<Account>  create(const QJsonObject& js);
        };



    protected:
            /**
                The user's unique Dropbox ID.
            */
        QString m_account_id;

            /**
                Details of a user's name.
            */
        Name m_name;

            /**
                The user's e-mail address. Do not rely on this without checking
                the ``email_verified`` field. Even then, it's possible that the
                user has since lost access to their e-mail.
            */
        QString m_email;

            /**
                Whether the user has verified their e-mail address.
            */
        bool m_email_verified;

            /**
                URL for the photo representing the user, if one is set.
            */
        QString m_profile_photo_url;

            /**
                Whether the user has been disabled.
            */
        bool m_disabled;

    };//Account

}//users
}//dropboxQt
