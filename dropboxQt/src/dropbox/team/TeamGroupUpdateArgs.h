/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamIncludeMembersArg.h"
#include "dropbox/team/TeamGroupSelector.h"
#include "dropbox/team_common/TeamCommonGroupManagementType.h"

namespace dropboxQt{
namespace team{
    class GroupUpdateArgs : public IncludeMembersArg{
        /**
            field: group: Specify a group.
            field: new_group_name: Optional argument. Set group name to this if
                provided.
            field: new_group_external_id: Optional argument. New group external
                ID. If the argument is None, the group's external_id won't be
                updated. If the argument is empty string, the group's external
                id will be cleared.
            field: new_group_management_type: Set new group management type, if
                provided.
        */

    public:
        GroupUpdateArgs(){};

        GroupUpdateArgs(const GroupSelector& arg){ m_group = arg; };
        virtual ~GroupUpdateArgs(){};

    public:
            /**
                Specify a group.
            */
        const GroupSelector& group()const{return m_group;};
        GroupUpdateArgs& setGroup(const GroupSelector& arg){m_group=arg;return *this;};

            /**
                Optional argument. Set group name to this if provided.
            */
        QString newGroupName()const{return m_new_group_name;};
        GroupUpdateArgs& setNewgroupname(const QString& arg){m_new_group_name=arg;return *this;};

            /**
                Optional argument. New group external ID. If the argument is
                None, the group's external_id won't be updated. If the argument
                is empty string, the group's external id will be cleared.
            */
        QString newGroupExternalId()const{return m_new_group_external_id;};
        GroupUpdateArgs& setNewgroupexternalid(const QString& arg){m_new_group_external_id=arg;return *this;};

            /**
                Set new group management type, if provided.
            */
        const team_common::GroupManagementType& newGroupManagementType()const{return m_new_group_management_type;};
        GroupUpdateArgs& setNewgroupmanagementtype(const team_common::GroupManagementType& arg){m_new_group_management_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupUpdateArgs>  create(const QByteArray& data);
            static std::unique_ptr<GroupUpdateArgs>  create(const QJsonObject& js);
        };



    protected:
            /**
                Specify a group.
            */
        GroupSelector m_group;

            /**
                Optional argument. Set group name to this if provided.
            */
        QString m_new_group_name;

            /**
                Optional argument. New group external ID. If the argument is
                None, the group's external_id won't be updated. If the argument
                is empty string, the group's external id will be cleared.
            */
        QString m_new_group_external_id;

            /**
                Set new group management type, if provided.
            */
        team_common::GroupManagementType m_new_group_management_type;

    };//GroupUpdateArgs

}//team
}//dropboxQt
