/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/users/UsersTeam.h"

namespace dropboxQt{
namespace sharing{
    class TeamMemberInfo{
        /**
            Information about a team member.

            field: team_info: Information about the member's team
            field: display_name: The display name of the user.
            field: member_id: ID of user as a member of a team. This field will
                only be present if the member is in the same team as current
                user.
        */

    public:
        TeamMemberInfo(){};

        TeamMemberInfo(const users::Team& arg){ m_team_info = arg; };
        virtual ~TeamMemberInfo(){};

    public:
            /**
                Information about the member's team
            */
        const users::Team& teamInfo()const{return m_team_info;};
        TeamMemberInfo& setTeaminfo(const users::Team& arg){m_team_info=arg;return *this;};

            /**
                The display name of the user.
            */
        QString displayName()const{return m_display_name;};
        TeamMemberInfo& setDisplayname(const QString& arg){m_display_name=arg;return *this;};

            /**
                ID of user as a member of a team. This field will only be
                present if the member is in the same team as current user.
            */
        QString memberId()const{return m_member_id;};
        TeamMemberInfo& setMemberid(const QString& arg){m_member_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TeamMemberInfo>  create(const QByteArray& data);
            static std::unique_ptr<TeamMemberInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                Information about the member's team
            */
        users::Team m_team_info;

            /**
                The display name of the user.
            */
        QString m_display_name;

            /**
                ID of user as a member of a team. This field will only be
                present if the member is in the same team as current user.
            */
        QString m_member_id;

    };//TeamMemberInfo

}//sharing
}//dropboxQt
