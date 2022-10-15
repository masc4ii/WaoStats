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
#include "dropbox/team/TeamUsersSelectorArg.h"

namespace dropboxQt{
namespace team{
    class GroupMembersSelector{
        /**
            Argument for selecting a group and a list of users.

            field: group: Specify a group.
            field: users: A list of users that are members of ``group``.
        */

    public:
        GroupMembersSelector(){};

        GroupMembersSelector(const GroupSelector& arg){ m_group = arg; };
        virtual ~GroupMembersSelector(){};

    public:
            /**
                Specify a group.
            */
        const GroupSelector& group()const{return m_group;};
        GroupMembersSelector& setGroup(const GroupSelector& arg){m_group=arg;return *this;};

            /**
                A list of users that are members of ``group``.
            */
        const UsersSelectorArg& users()const{return m_users;};
        GroupMembersSelector& setUsers(const UsersSelectorArg& arg){m_users=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembersSelector>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembersSelector>  create(const QJsonObject& js);
        };



    protected:
            /**
                Specify a group.
            */
        GroupSelector m_group;

            /**
                A list of users that are members of ``group``.
            */
        UsersSelectorArg m_users;

    };//GroupMembersSelector

}//team
}//dropboxQt
