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
    class GroupsGetInfoError{
        /**
            field: group_not_on_team: The group is not on your team.
        */
    public:
        enum Tag{

        /*The group is not on your team.*/
        GroupsGetInfoError_GROUP_NOT_ON_TEAM,
        /*None*/
        GroupsGetInfoError_OTHER
        };

        GroupsGetInfoError(){}
        GroupsGetInfoError(Tag v):m_tag(v){}
        virtual ~GroupsGetInfoError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsGetInfoError>  create(const QByteArray& data);
            static std::unique_ptr<GroupsGetInfoError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupsGetInfoError

}//team
}//dropboxQt
