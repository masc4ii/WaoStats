/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team_common/TeamCommonGroupSummary.h"
#include "dropbox/team_common/TeamCommonGroupType.h"

namespace dropboxQt{
namespace sharing{
    class GroupInfo : public team_common::GroupSummary{
        /**
            The information about a group. Groups is a way to manage a list of
            users  who need same access permission to the shared folder.

            field: group_type: The type of group.
            field: is_owner: If the current user is an owner of the group.
            field: same_team: If the group is owned by the current user's team.
        */

    public:
        GroupInfo(){};

        GroupInfo(const team_common::GroupType& arg){ m_group_type = arg; };
        virtual ~GroupInfo(){};

    public:
            /**
                The type of group.
            */
        const team_common::GroupType& groupType()const{return m_group_type;};
        GroupInfo& setGrouptype(const team_common::GroupType& arg){m_group_type=arg;return *this;};

            /**
                If the current user is an owner of the group.
            */
        bool isOwner()const{return m_is_owner;};
        GroupInfo& setIsowner(const bool& arg){m_is_owner=arg;return *this;};

            /**
                If the group is owned by the current user's team.
            */
        bool sameTeam()const{return m_same_team;};
        GroupInfo& setSameteam(const bool& arg){m_same_team=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupInfo>  create(const QByteArray& data);
            static std::unique_ptr<GroupInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                The type of group.
            */
        team_common::GroupType m_group_type;

            /**
                If the current user is an owner of the group.
            */
        bool m_is_owner;

            /**
                If the group is owned by the current user's team.
            */
        bool m_same_team;

    };//GroupInfo

}//sharing
}//dropboxQt
