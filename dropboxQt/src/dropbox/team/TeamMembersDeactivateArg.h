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
    class MembersDeactivateArg{
        /**
            Exactly one of team_member_id, email, or external_id must be
            provided to identify the user account.

            field: user: Identity of user to remove/suspend.
            field: wipe_data: If provided, controls if the user's data will be
                deleted on their linked devices.
        */

    public:
        MembersDeactivateArg():
        m_wipe_data(false)
        {};

        MembersDeactivateArg(const UserSelectorArg& arg):
        m_wipe_data(false)
        { m_user = arg; };
        virtual ~MembersDeactivateArg(){};

    public:
            /**
                Identity of user to remove/suspend.
            */
        const UserSelectorArg& user()const{return m_user;};
        MembersDeactivateArg& setUser(const UserSelectorArg& arg){m_user=arg;return *this;};

            /**
                If provided, controls if the user's data will be deleted on
                their linked devices.
            */
        bool wipeData()const{return m_wipe_data;};
        MembersDeactivateArg& setWipedata(const bool& arg){m_wipe_data=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersDeactivateArg>  create(const QByteArray& data);
            static std::unique_ptr<MembersDeactivateArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Identity of user to remove/suspend.
            */
        UserSelectorArg m_user;

            /**
                If provided, controls if the user's data will be deleted on
                their linked devices.
            */
        bool m_wipe_data;

    };//MembersDeactivateArg

}//team
}//dropboxQt
