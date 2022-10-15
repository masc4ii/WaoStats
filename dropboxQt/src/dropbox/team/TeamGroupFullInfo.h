/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team_common/TeamCommonGroupSummary.h"
#include "dropbox/team/TeamGroupMemberInfo.h"

namespace dropboxQt{
namespace team{
    class GroupFullInfo : public team_common::GroupSummary{
        /**
            Full description of a group.

            field: members: List of group members.
            field: created: The group creation time as a UTC timestamp in
                milliseconds since the Unix epoch.
        */

    public:
        GroupFullInfo(){};

        GroupFullInfo(const std::list <GroupMemberInfo>& arg){ m_members = arg; };
        virtual ~GroupFullInfo(){};

    public:
            /**
                List of group members.
            */
        const std::list <GroupMemberInfo>& members()const{return m_members;};
        GroupFullInfo& setMembers(const std::list <GroupMemberInfo>& arg){m_members=arg;return *this;};

            /**
                The group creation time as a UTC timestamp in milliseconds since
                the Unix epoch.
            */
        int created()const{return m_created;};
        GroupFullInfo& setCreated(const int& arg){m_created=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupFullInfo>  create(const QByteArray& data);
            static std::unique_ptr<GroupFullInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of group members.
            */
        std::list <GroupMemberInfo> m_members;

            /**
                The group creation time as a UTC timestamp in milliseconds since
                the Unix epoch.
            */
        int m_created = {0};

    };//GroupFullInfo

}//team
}//dropboxQt
