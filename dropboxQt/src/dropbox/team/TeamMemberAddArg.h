/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamAdminTier.h"

namespace dropboxQt{
namespace team{
    class MemberAddArg{
        /**
            field: member_given_name: Member's first name.
            field: member_surname: Member's last name.
            field: member_external_id: External ID for member.
            field: send_welcome_email: Whether to send a welcome email to the
                member. If send_welcome_email is false, no email invitation will
                be sent to the user. This may be useful for apps using single
                sign-on (SSO) flows for onboarding that want to handle
                announcements themselves.
        */

    public:
        MemberAddArg():
        m_send_welcome_email(false)
        ,m_role(AdminTier::AdminTier_MEMBER_ONLY)
        {};

        MemberAddArg(const QString& arg):
        m_send_welcome_email(false)
        ,m_role(AdminTier::AdminTier_MEMBER_ONLY)
        { m_member_email = arg; };
        virtual ~MemberAddArg(){};

    public:
        QString memberEmail()const{return m_member_email;};
        MemberAddArg& setMemberemail(const QString& arg){m_member_email=arg;return *this;};

            /**
                Member's first name.
            */
        QString memberGivenName()const{return m_member_given_name;};
        MemberAddArg& setMembergivenname(const QString& arg){m_member_given_name=arg;return *this;};

            /**
                Member's last name.
            */
        QString memberSurname()const{return m_member_surname;};
        MemberAddArg& setMembersurname(const QString& arg){m_member_surname=arg;return *this;};

            /**
                External ID for member.
            */
        QString memberExternalId()const{return m_member_external_id;};
        MemberAddArg& setMemberexternalid(const QString& arg){m_member_external_id=arg;return *this;};

            /**
                Whether to send a welcome email to the member. If
                send_welcome_email is false, no email invitation will be sent to
                the user. This may be useful for apps using single sign-on (SSO)
                flows for onboarding that want to handle announcements
                themselves.
            */
        bool sendWelcomeEmail()const{return m_send_welcome_email;};
        MemberAddArg& setSendwelcomeemail(const bool& arg){m_send_welcome_email=arg;return *this;};

        const AdminTier& role()const{return m_role;};
        MemberAddArg& setRole(const AdminTier& arg){m_role=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberAddArg>  create(const QByteArray& data);
            static std::unique_ptr<MemberAddArg>  create(const QJsonObject& js);
        };



    protected:
        QString m_member_email;

            /**
                Member's first name.
            */
        QString m_member_given_name;

            /**
                Member's last name.
            */
        QString m_member_surname;

            /**
                External ID for member.
            */
        QString m_member_external_id;

            /**
                Whether to send a welcome email to the member. If
                send_welcome_email is false, no email invitation will be sent to
                the user. This may be useful for apps using single sign-on (SSO)
                flows for onboarding that want to handle announcements
                themselves.
            */
        bool m_send_welcome_email;

        AdminTier m_role;

    };//MemberAddArg

}//team
}//dropboxQt
