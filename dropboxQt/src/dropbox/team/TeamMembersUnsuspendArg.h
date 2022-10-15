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
    class MembersUnsuspendArg{
        /**
            Exactly one of team_member_id, email, or external_id must be
            provided to identify the user account.

            field: user: Identity of user to unsuspend.
        */

    public:
        MembersUnsuspendArg(){};

        MembersUnsuspendArg(const UserSelectorArg& arg){ m_user = arg; };
        virtual ~MembersUnsuspendArg(){};

    public:
            /**
                Identity of user to unsuspend.
            */
        const UserSelectorArg& user()const{return m_user;};
        MembersUnsuspendArg& setUser(const UserSelectorArg& arg){m_user=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersUnsuspendArg>  create(const QByteArray& data);
            static std::unique_ptr<MembersUnsuspendArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Identity of user to unsuspend.
            */
        UserSelectorArg m_user;

    };//MembersUnsuspendArg

}//team
}//dropboxQt
