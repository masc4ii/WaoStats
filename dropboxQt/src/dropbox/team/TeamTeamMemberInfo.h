/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamTeamMemberProfile.h"
#include "dropbox/team/TeamAdminTier.h"

namespace dropboxQt{
namespace team{
    class TeamMemberInfo{
        /**
            Information about a team member.

            field: profile: Profile of a user as a member of a team.
            field: role: The user's role in the team.
        */

    public:
        TeamMemberInfo(){};

        TeamMemberInfo(const TeamMemberProfile& arg){ m_profile = arg; };
        virtual ~TeamMemberInfo(){};

    public:
            /**
                Profile of a user as a member of a team.
            */
        const TeamMemberProfile& profile()const{return m_profile;};
        TeamMemberInfo& setProfile(const TeamMemberProfile& arg){m_profile=arg;return *this;};

            /**
                The user's role in the team.
            */
        const AdminTier& role()const{return m_role;};
        TeamMemberInfo& setRole(const AdminTier& arg){m_role=arg;return *this;};

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
                Profile of a user as a member of a team.
            */
        TeamMemberProfile m_profile;

            /**
                The user's role in the team.
            */
        AdminTier m_role;

    };//TeamMemberInfo

}//team
}//dropboxQt
