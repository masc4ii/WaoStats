/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class MemberPolicy{
        /**
            Policy governing who can be a member of a shared folder. Only
            applicable to folders owned by a user on a team.

            field: team: Only a teammate can become a member.
            field: anyone: Anyone can become a member.
        */
    public:
        enum Tag{

        /*Only a teammate can become a member.*/
        MemberPolicy_TEAM,
        /*Anyone can become a member.*/
        MemberPolicy_ANYONE,
        /*None*/
        MemberPolicy_OTHER
        };

        MemberPolicy(){}
        MemberPolicy(Tag v):m_tag(v){}
        virtual ~MemberPolicy(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberPolicy>  create(const QByteArray& data);
            static std::unique_ptr<MemberPolicy>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MemberPolicy

}//sharing
}//dropboxQt
