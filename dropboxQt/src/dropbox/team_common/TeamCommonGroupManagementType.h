/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_common"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team_common{
    class GroupManagementType{
        /**
            The group type determines how a group is managed.

            field: company_managed: A group which is managed by team admins
                only.
            field: user_managed: A group which is managed by selected users.
        */
    public:
        enum Tag{

        /*A group which is managed by team admins only.*/
        GroupManagementType_COMPANY_MANAGED,
        /*A group which is managed by selected users.*/
        GroupManagementType_USER_MANAGED,
        /*None*/
        GroupManagementType_OTHER
        };

        GroupManagementType(){}
        GroupManagementType(Tag v):m_tag(v){}
        virtual ~GroupManagementType(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupManagementType>  create(const QByteArray& data);
            static std::unique_ptr<GroupManagementType>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupManagementType

}//team_common
}//dropboxQt
