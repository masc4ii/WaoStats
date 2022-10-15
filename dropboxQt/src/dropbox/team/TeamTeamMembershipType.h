/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team{
    class TeamMembershipType{
        /**
            field: full: User uses a license and has full access to team
                resources like the shared quota.
            field: limited: User does not have access to the shared quota and
                team admins have restricted administrative control.
        */
    public:
        enum Tag{

        /*User uses a license and has full access to team resources like the shared quota.*/
        TeamMembershipType_FULL,
        /*User does not have access to the shared quota and team admins have restricted administrative control.*/
        TeamMembershipType_LIMITED
        };

        TeamMembershipType(){}
        TeamMembershipType(Tag v):m_tag(v){}
        virtual ~TeamMembershipType(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TeamMembershipType>  create(const QByteArray& data);
            static std::unique_ptr<TeamMembershipType>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//TeamMembershipType

}//team
}//dropboxQt
