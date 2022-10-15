/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMemberProfile.h"

namespace dropboxQt{
namespace team{
    class TeamMemberProfile : public MemberProfile{
        /**
            Profile of a user as a member of a team.

            field: groups: List of group IDs of groups that the user belongs to.
        */

    public:
        TeamMemberProfile(){};

        TeamMemberProfile(const std::list <QString>& arg){ m_groups = arg; };
        virtual ~TeamMemberProfile(){};

    public:
            /**
                List of group IDs of groups that the user belongs to.
            */
        const std::list <QString>& groups()const{return m_groups;};
        TeamMemberProfile& setGroups(const std::list <QString>& arg){m_groups=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TeamMemberProfile>  create(const QByteArray& data);
            static std::unique_ptr<TeamMemberProfile>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of group IDs of groups that the user belongs to.
            */
        std::list <QString> m_groups;

    };//TeamMemberProfile

}//team
}//dropboxQt
