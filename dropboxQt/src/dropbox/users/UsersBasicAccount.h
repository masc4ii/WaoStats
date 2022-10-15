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

namespace dropboxQt{
namespace users{
    class BasicAccount : public Account{
        /**
            Basic information about any account.

            field: is_teammate: Whether this user is a teammate of the current
                user. If this account is the current user's account, then this
                will be ``True``.
            field: team_member_id: The user's unique team member id. This field
                will only be present if the user is part of a team and
                ``is_teammate`` is ``True``.
        */

    public:
        BasicAccount(){};

        BasicAccount(const bool& arg){ m_is_teammate = arg; };
        virtual ~BasicAccount(){};

    public:
            /**
                Whether this user is a teammate of the current user. If this
                account is the current user's account, then this will be
                ``True``.
            */
        bool isTeammate()const{return m_is_teammate;};
        BasicAccount& setIsteammate(const bool& arg){m_is_teammate=arg;return *this;};

            /**
                The user's unique team member id. This field will only be
                present if the user is part of a team and ``is_teammate`` is
                ``True``.
            */
        QString teamMemberId()const{return m_team_member_id;};
        BasicAccount& setTeammemberid(const QString& arg){m_team_member_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<BasicAccount>  create(const QByteArray& data);
            static std::unique_ptr<BasicAccount>  create(const QJsonObject& js);
        };



    protected:
            /**
                Whether this user is a teammate of the current user. If this
                account is the current user's account, then this will be
                ``True``.
            */
        bool m_is_teammate;

            /**
                The user's unique team member id. This field will only be
                present if the user is part of a team and ``is_teammate`` is
                ``True``.
            */
        QString m_team_member_id;

    };//BasicAccount

}//users
}//dropboxQt
