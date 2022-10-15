/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team_policies{
    class SharedFolderMemberPolicy{
        /**
            Policy governing who can be a member of a folder shared by a team
            member.

            field: team: Only a teammate can be a member of a folder shared by a
                team member.
            field: anyone: Anyone can be a member of a folder shared by a team
                member.
        */
    public:
        enum Tag{

        /*Only a teammate can be a member of a folder shared by a team member.*/
        SharedFolderMemberPolicy_TEAM,
        /*Anyone can be a member of a folder shared by a team member.*/
        SharedFolderMemberPolicy_ANYONE,
        /*None*/
        SharedFolderMemberPolicy_OTHER
        };

        SharedFolderMemberPolicy(){}
        SharedFolderMemberPolicy(Tag v):m_tag(v){}
        virtual ~SharedFolderMemberPolicy(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderMemberPolicy>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderMemberPolicy>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedFolderMemberPolicy

}//team_policies
}//dropboxQt
