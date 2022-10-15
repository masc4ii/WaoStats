/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupSelector.h"
#include "dropbox/team/TeamUserSelectorArg.h"

namespace dropboxQt{
namespace team{
    class GroupMemberSelector{
        /**
            Argument for selecting a group and a single user.

            field: group: Specify a group.
            field: user: Identity of a user that is a member of ``group``.
        */

    public:
        GroupMemberSelector(){};

        GroupMemberSelector(const GroupSelector& arg){ m_group = arg; };
        virtual ~GroupMemberSelector(){};

    public:
            /**
                Specify a group.
            */
        const GroupSelector& group()const{return m_group;};
        GroupMemberSelector& setGroup(const GroupSelector& arg){m_group=arg;return *this;};

            /**
                Identity of a user that is a member of ``group``.
            */
        const UserSelectorArg& user()const{return m_user;};
        GroupMemberSelector& setUser(const UserSelectorArg& arg){m_user=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMemberSelector>  create(const QByteArray& data);
            static std::unique_ptr<GroupMemberSelector>  create(const QJsonObject& js);
        };



    protected:
            /**
                Specify a group.
            */
        GroupSelector m_group;

            /**
                Identity of a user that is a member of ``group``.
            */
        UserSelectorArg m_user;

    };//GroupMemberSelector

}//team
}//dropboxQt
