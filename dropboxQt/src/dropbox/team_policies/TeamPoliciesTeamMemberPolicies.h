/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team_policies/TeamPoliciesTeamSharingPolicies.h"
#include "dropbox/team_policies/TeamPoliciesEmmState.h"

namespace dropboxQt{
namespace team_policies{
    class TeamMemberPolicies{
        /**
            Policies governing team members.

            field: sharing: Policies governing sharing.
            field: emm_state: This describes the Enterprise Mobility Management
                (EMM) state for this team. This information can be used to
                understand if an organization is integrating with a third-party
                EMM vendor to further manage and apply restrictions upon the
                team's Dropbox usage on mobile devices. This is a new feature
                and in the future we'll be adding more new fields and additional
                documentation.
        */

    public:
        TeamMemberPolicies(){};

        TeamMemberPolicies(const TeamSharingPolicies& arg){ m_sharing = arg; };
        virtual ~TeamMemberPolicies(){};

    public:
            /**
                Policies governing sharing.
            */
        const TeamSharingPolicies& sharing()const{return m_sharing;};
        TeamMemberPolicies& setSharing(const TeamSharingPolicies& arg){m_sharing=arg;return *this;};

            /**
                This describes the Enterprise Mobility Management (EMM) state
                for this team. This information can be used to understand if an
                organization is integrating with a third-party EMM vendor to
                further manage and apply restrictions upon the team's Dropbox
                usage on mobile devices. This is a new feature and in the future
                we'll be adding more new fields and additional documentation.
            */
        const EmmState& emmState()const{return m_emm_state;};
        TeamMemberPolicies& setEmmstate(const EmmState& arg){m_emm_state=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TeamMemberPolicies>  create(const QByteArray& data);
            static std::unique_ptr<TeamMemberPolicies>  create(const QJsonObject& js);
        };



    protected:
            /**
                Policies governing sharing.
            */
        TeamSharingPolicies m_sharing;

            /**
                This describes the Enterprise Mobility Management (EMM) state
                for this team. This information can be used to understand if an
                organization is integrating with a third-party EMM vendor to
                further manage and apply restrictions upon the team's Dropbox
                usage on mobile devices. This is a new feature and in the future
                we'll be adding more new fields and additional documentation.
            */
        EmmState m_emm_state;

    };//TeamMemberPolicies

}//team_policies
}//dropboxQt
