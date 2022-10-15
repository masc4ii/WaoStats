/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupSelectorError.h"

namespace dropboxQt{
namespace team{
    class GroupDeleteError{
        /**
            field: group_already_deleted: This group has already been deleted.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER,
        /*This group has already been deleted.*/
        GroupDeleteError_GROUP_ALREADY_DELETED
        };

        GroupDeleteError(){}
        GroupDeleteError(Tag v):m_tag(v){}
        virtual ~GroupDeleteError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupDeleteError>  create(const QByteArray& data);
            static std::unique_ptr<GroupDeleteError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupDeleteError

}//team
}//dropboxQt
