/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/users/UsersAccount.h"
#include "dropbox/users/UsersFullTeam.h"
#include "dropbox/users/UsersAccountType.h"

namespace dropboxQt{
namespace users{
    class FullAccount : public Account{
        /**
            Detailed information about the current user's account.

            field: country: The user's two-letter country code, if available.
                Country codes are based on `ISO 3166-1
                <http://en.wikipedia.org/wiki/ISO_3166-1>`_.
            field: locale: The language that the user specified. Locale tags
                will be `IETF language tags
                <http://en.wikipedia.org/wiki/IETF_language_tag>`_.
            field: referral_link: The user's `referral link
                <https://www.dropbox.com/referrals>`_.
            field: team: If this account is a member of a team, information
                about that team.
            field: team_member_id: This account's unique team member id. This
                field will only be present if ``team`` is present.
            field: is_paired: Whether the user has a personal and work account.
                If the current account is personal, then ``team`` will always be
                None, but ``is_paired`` will indicate if a work account is
                linked.
            field: account_type: What type of account this user has.
        */

    public:
        FullAccount(){};

        FullAccount(const QString& arg){ m_country = arg; };
        virtual ~FullAccount(){};

    public:
            /**
                The user's two-letter country code, if available. Country codes
                are based on `ISO 3166-1
                <http://en.wikipedia.org/wiki/ISO_3166-1>`_.
            */
        QString country()const{return m_country;};
        FullAccount& setCountry(const QString& arg){m_country=arg;return *this;};

            /**
                The language that the user specified. Locale tags will be `IETF
                language tags
                <http://en.wikipedia.org/wiki/IETF_language_tag>`_.
            */
        QString locale()const{return m_locale;};
        FullAccount& setLocale(const QString& arg){m_locale=arg;return *this;};

            /**
                The user's `referral link <https://www.dropbox.com/referrals>`_.
            */
        QString referralLink()const{return m_referral_link;};
        FullAccount& setReferrallink(const QString& arg){m_referral_link=arg;return *this;};

            /**
                If this account is a member of a team, information about that
                team.
            */
        const FullTeam& team()const{return m_team;};
        FullAccount& setTeam(const FullTeam& arg){m_team=arg;return *this;};

            /**
                This account's unique team member id. This field will only be
                present if ``team`` is present.
            */
        QString teamMemberId()const{return m_team_member_id;};
        FullAccount& setTeammemberid(const QString& arg){m_team_member_id=arg;return *this;};

            /**
                Whether the user has a personal and work account. If the current
                account is personal, then ``team`` will always be None, but
                ``is_paired`` will indicate if a work account is linked.
            */
        bool isPaired()const{return m_is_paired;};
        FullAccount& setIspaired(const bool& arg){m_is_paired=arg;return *this;};

            /**
                What type of account this user has.
            */
        const AccountType& accountType()const{return m_account_type;};
        FullAccount& setAccounttype(const AccountType& arg){m_account_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FullAccount>  create(const QByteArray& data);
            static std::unique_ptr<FullAccount>  create(const QJsonObject& js);
        };



    protected:
            /**
                The user's two-letter country code, if available. Country codes
                are based on `ISO 3166-1
                <http://en.wikipedia.org/wiki/ISO_3166-1>`_.
            */
        QString m_country;

            /**
                The language that the user specified. Locale tags will be `IETF
                language tags
                <http://en.wikipedia.org/wiki/IETF_language_tag>`_.
            */
        QString m_locale;

            /**
                The user's `referral link <https://www.dropbox.com/referrals>`_.
            */
        QString m_referral_link;

            /**
                If this account is a member of a team, information about that
                team.
            */
        FullTeam m_team;

            /**
                This account's unique team member id. This field will only be
                present if ``team`` is present.
            */
        QString m_team_member_id;

            /**
                Whether the user has a personal and work account. If the current
                account is personal, then ``team`` will always be None, but
                ``is_paired`` will indicate if a work account is linked.
            */
        bool m_is_paired;

            /**
                What type of account this user has.
            */
        AccountType m_account_type;

    };//FullAccount

}//users
}//dropboxQt
