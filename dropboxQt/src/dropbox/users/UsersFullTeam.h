/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/users/UsersTeam.h"
#include "dropbox/team_policies/TeamPoliciesTeamSharingPolicies.h"

namespace dropboxQt{
namespace users{
    class FullTeam : public Team{
        /**
            Detailed information about a team.

            field: sharing_policies: Team policies governing sharing.
        */

    public:
        FullTeam(){};

        FullTeam(const team_policies::TeamSharingPolicies& arg){ m_sharing_policies = arg; };
        virtual ~FullTeam(){};

    public:
            /**
                Team policies governing sharing.
            */
        const team_policies::TeamSharingPolicies& sharingPolicies()const{return m_sharing_policies;};
        FullTeam& setSharingpolicies(const team_policies::TeamSharingPolicies& arg){m_sharing_policies=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FullTeam>  create(const QByteArray& data);
            static std::unique_ptr<FullTeam>  create(const QJsonObject& js);
        };



    protected:
            /**
                Team policies governing sharing.
            */
        team_policies::TeamSharingPolicies m_sharing_policies;

    };//FullTeam

}//users
}//dropboxQt
