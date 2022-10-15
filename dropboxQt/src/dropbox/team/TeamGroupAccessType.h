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
    class GroupAccessType{
        /**
            Role of a user in group.

            field: member: User is a member of the group, but has no special
                permissions.
            field: owner: User can rename the group, and add/remove members.
        */
    public:
        enum Tag{

        /*User is a member of the group, but has no special permissions.*/
        GroupAccessType_MEMBER,
        /*User can rename the group, and add/remove members.*/
        GroupAccessType_OWNER
        };

        GroupAccessType(){}
        GroupAccessType(Tag v):m_tag(v){}
        virtual ~GroupAccessType(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupAccessType>  create(const QByteArray& data);
            static std::unique_ptr<GroupAccessType>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupAccessType

}//team
}//dropboxQt
