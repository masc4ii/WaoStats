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
    class GroupMembersAddError{
        /**
            field: duplicate_user: You cannot add duplicate users. One or more
                of the members you are trying to add is already a member of the
                group.
            field: group_not_in_team: Group is not in this team. You cannot add
                members to a group that is outside of your team.
            field: members_not_in_team: These members are not part of your team.
                Currently, you cannot add members to a group if they are not
                part of your team, though this may change in a subsequent
                version. To add new members to your Dropbox Business team, use
                the :meth:`members_add` endpoint.
            field: users_not_found: These users were not found in Dropbox.
            field: user_must_be_active_to_be_owner: A suspended user cannot be
                added to a group as ``GroupAccessType.owner``.
            field: user_cannot_be_manager_of_company_managed_group: A
                company-managed group cannot be managed by a user.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER,
        /*You cannot add duplicate users. One or more of the members you are trying to add is already a member of the group.*/
        GroupMembersAddError_DUPLICATE_USER,
        /*Group is not in this team. You cannot add members to a group that is outside of your team.*/
        GroupMembersAddError_GROUP_NOT_IN_TEAM,
        /*These members are not part of your team. Currently, you cannot add members to a group if they are not part of your team, though this may change in a subsequent version. To add new members to your Dropbox Business team, use the :route:`members/add` endpoint.*/
        GroupMembersAddError_MEMBERS_NOT_IN_TEAM,
        /*These users were not found in Dropbox.*/
        GroupMembersAddError_USERS_NOT_FOUND,
        /*A suspended user cannot be added to a group as :field:`GroupAccessType.owner`.*/
        GroupMembersAddError_USER_MUST_BE_ACTIVE_TO_BE_OWNER,
        /*A company-managed group cannot be managed by a user.*/
        GroupMembersAddError_USER_CANNOT_BE_MANAGER_OF_COMPANY_MANAGED_GROUP
        };

        GroupMembersAddError(){}
        GroupMembersAddError(Tag v):m_tag(v){}
        virtual ~GroupMembersAddError(){}

        Tag tag()const{return m_tag;}
        ///These members are not part of your team. Currently, you cannot add members to a group if they are not part of your team, though this may change in a subsequent version. To add new members to your Dropbox Business team, use the :route:`members/add` endpoint.
        const std::list <QString>& getMembersNotInTeam()const{API_CHECK_STATE((GroupMembersAddError_MEMBERS_NOT_IN_TEAM == m_tag), "expected tag: GroupMembersAddError_MEMBERS_NOT_IN_TEAM", m_tag);return m_members_not_in_team;};

        ///These users were not found in Dropbox.
        const std::list <QString>& getUsersNotFound()const{API_CHECK_STATE((GroupMembersAddError_USERS_NOT_FOUND == m_tag), "expected tag: GroupMembersAddError_USERS_NOT_FOUND", m_tag);return m_users_not_found;};

        ///A company-managed group cannot be managed by a user.
        const std::list <QString>& getUserCannotBeManagerOfCompanyManagedGroup()const{API_CHECK_STATE((GroupMembersAddError_USER_CANNOT_BE_MANAGER_OF_COMPANY_MANAGED_GROUP == m_tag), "expected tag: GroupMembersAddError_USER_CANNOT_BE_MANAGER_OF_COMPANY_MANAGED_GROUP", m_tag);return m_user_cannot_be_manager_of_company_managed_group;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembersAddError>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembersAddError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        std::list <QString> m_members_not_in_team;
        std::list <QString> m_users_not_found;
        std::list <QString> m_user_cannot_be_manager_of_company_managed_group;
    };//GroupMembersAddError

}//team
}//dropboxQt
