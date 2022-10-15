/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/users/UsersIndividualSpaceAllocation.h"
#include "dropbox/users/UsersTeamSpaceAllocation.h"

namespace dropboxQt{
namespace users{
    class SpaceAllocation{
        /**
            Space is allocated differently based on the type of account.

            field: individual: The user's space allocation applies only to their
                individual account.
            field: team: The user shares space with other members of their team.
        */
    public:
        enum Tag{

        /*The user's space allocation applies only to their individual account.*/
        SpaceAllocation_INDIVIDUAL,
        /*The user shares space with other members of their team.*/
        SpaceAllocation_TEAM,
        /*None*/
        SpaceAllocation_OTHER
        };

        SpaceAllocation(){}
        SpaceAllocation(Tag v):m_tag(v){}
        virtual ~SpaceAllocation(){}

        Tag tag()const{return m_tag;}
        ///The user's space allocation applies only to their individual account.
        const IndividualSpaceAllocation& getIndividual()const{API_CHECK_STATE((SpaceAllocation_INDIVIDUAL == m_tag), "expected tag: SpaceAllocation_INDIVIDUAL", m_tag);return m_individual;};

        ///The user shares space with other members of their team.
        const TeamSpaceAllocation& getTeam()const{API_CHECK_STATE((SpaceAllocation_TEAM == m_tag), "expected tag: SpaceAllocation_TEAM", m_tag);return m_team;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SpaceAllocation>  create(const QByteArray& data);
            static std::unique_ptr<SpaceAllocation>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        IndividualSpaceAllocation m_individual;
        TeamSpaceAllocation m_team;
    };//SpaceAllocation

}//users
}//dropboxQt
