/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamUserSelectorArg.h"

namespace dropboxQt{
namespace team{
    class MembersSetProfileArg{
        /**
            Exactly one of team_member_id, email, or external_id must be
            provided to identify the user account. At least one of new_email,
            new_external_id, new_given_name, and/or new_surname must be
            provided.

            field: user: Identity of user whose profile will be set.
            field: new_email: New email for member.
            field: new_external_id: New external ID for member.
            field: new_given_name: New given name for member.
            field: new_surname: New surname for member.
        */

    public:
        MembersSetProfileArg(){};

        MembersSetProfileArg(const UserSelectorArg& arg){ m_user = arg; };
        virtual ~MembersSetProfileArg(){};

    public:
            /**
                Identity of user whose profile will be set.
            */
        const UserSelectorArg& user()const{return m_user;};
        MembersSetProfileArg& setUser(const UserSelectorArg& arg){m_user=arg;return *this;};

            /**
                New email for member.
            */
        QString newEmail()const{return m_new_email;};
        MembersSetProfileArg& setNewemail(const QString& arg){m_new_email=arg;return *this;};

            /**
                New external ID for member.
            */
        QString newExternalId()const{return m_new_external_id;};
        MembersSetProfileArg& setNewexternalid(const QString& arg){m_new_external_id=arg;return *this;};

            /**
                New given name for member.
            */
        QString newGivenName()const{return m_new_given_name;};
        MembersSetProfileArg& setNewgivenname(const QString& arg){m_new_given_name=arg;return *this;};

            /**
                New surname for member.
            */
        QString newSurname()const{return m_new_surname;};
        MembersSetProfileArg& setNewsurname(const QString& arg){m_new_surname=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersSetProfileArg>  create(const QByteArray& data);
            static std::unique_ptr<MembersSetProfileArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Identity of user whose profile will be set.
            */
        UserSelectorArg m_user;

            /**
                New email for member.
            */
        QString m_new_email;

            /**
                New external ID for member.
            */
        QString m_new_external_id;

            /**
                New given name for member.
            */
        QString m_new_given_name;

            /**
                New surname for member.
            */
        QString m_new_surname;

    };//MembersSetProfileArg

}//team
}//dropboxQt
