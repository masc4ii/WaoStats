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
    class SharedFolderJoinPolicy{
        /**
            Policy governing which shared folders a team member can join.

            field: from_team_only: Team members can only join folders shared by
                teammates.
            field: from_anyone: Team members can join any shared folder,
                including those shared by users outside the team.
        */
    public:
        enum Tag{

        /*Team members can only join folders shared by teammates.*/
        SharedFolderJoinPolicy_FROM_TEAM_ONLY,
        /*Team members can join any shared folder, including those shared by users outside the team.*/
        SharedFolderJoinPolicy_FROM_ANYONE,
        /*None*/
        SharedFolderJoinPolicy_OTHER
        };

        SharedFolderJoinPolicy(){}
        SharedFolderJoinPolicy(Tag v):m_tag(v){}
        virtual ~SharedFolderJoinPolicy(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderJoinPolicy>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderJoinPolicy>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedFolderJoinPolicy

}//team_policies
}//dropboxQt
