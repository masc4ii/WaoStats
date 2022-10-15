/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamIncludeMembersArg.h"
#include "dropbox/team/TeamGroupSelector.h"
#include "dropbox/team/TeamMemberAccess.h"

namespace dropboxQt{
namespace team{
    class GroupMembersAddArg : public IncludeMembersArg{
        /**
            field: group: Group to which users will be added.
            field: members: List of users to be added to the group.
        */

    public:
        GroupMembersAddArg(){};

        GroupMembersAddArg(const GroupSelector& arg){ m_group = arg; };
        virtual ~GroupMembersAddArg(){};

    public:
            /**
                Group to which users will be added.
            */
        const GroupSelector& group()const{return m_group;};
        GroupMembersAddArg& setGroup(const GroupSelector& arg){m_group=arg;return *this;};

            /**
                List of users to be added to the group.
            */
        const std::list <MemberAccess>& members()const{return m_members;};
        GroupMembersAddArg& setMembers(const std::list <MemberAccess>& arg){m_members=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembersAddArg>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembersAddArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Group to which users will be added.
            */
        GroupSelector m_group;

            /**
                List of users to be added to the group.
            */
        std::list <MemberAccess> m_members;

    };//GroupMembersAddArg

}//team
}//dropboxQt
