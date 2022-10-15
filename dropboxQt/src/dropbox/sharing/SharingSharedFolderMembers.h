/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingUserMembershipInfo.h"
#include "dropbox/sharing/SharingGroupMembershipInfo.h"
#include "dropbox/sharing/SharingInviteeMembershipInfo.h"

namespace dropboxQt{
namespace sharing{
    class SharedFolderMembers{
        /**
            Shared folder user and group membership.

            field: users: The list of user members of the shared folder.
            field: groups: The list of group members of the shared folder.
            field: invitees: The list of invitees to the shared folder.
            field: cursor: Present if there are additional shared folder members
                that have not been returned yet. Pass the cursor into
                :meth:`list_folder_members_continue` to list additional members.
        */

    public:
        SharedFolderMembers(){};

        SharedFolderMembers(const std::list <UserMembershipInfo>& arg){ m_users = arg; };
        virtual ~SharedFolderMembers(){};

    public:
            /**
                The list of user members of the shared folder.
            */
        const std::list <UserMembershipInfo>& users()const{return m_users;};
        SharedFolderMembers& setUsers(const std::list <UserMembershipInfo>& arg){m_users=arg;return *this;};

            /**
                The list of group members of the shared folder.
            */
        const std::list <GroupMembershipInfo>& groups()const{return m_groups;};
        SharedFolderMembers& setGroups(const std::list <GroupMembershipInfo>& arg){m_groups=arg;return *this;};

            /**
                The list of invitees to the shared folder.
            */
        const std::list <InviteeMembershipInfo>& invitees()const{return m_invitees;};
        SharedFolderMembers& setInvitees(const std::list <InviteeMembershipInfo>& arg){m_invitees=arg;return *this;};

            /**
                Present if there are additional shared folder members that have
                not been returned yet. Pass the cursor into
                :meth:`list_folder_members_continue` to list additional members.
            */
        QString cursor()const{return m_cursor;};
        SharedFolderMembers& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderMembers>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderMembers>  create(const QJsonObject& js);
        };



    protected:
            /**
                The list of user members of the shared folder.
            */
        std::list <UserMembershipInfo> m_users;

            /**
                The list of group members of the shared folder.
            */
        std::list <GroupMembershipInfo> m_groups;

            /**
                The list of invitees to the shared folder.
            */
        std::list <InviteeMembershipInfo> m_invitees;

            /**
                Present if there are additional shared folder members that have
                not been returned yet. Pass the cursor into
                :meth:`list_folder_members_continue` to list additional members.
            */
        QString m_cursor;

    };//SharedFolderMembers

}//sharing
}//dropboxQt
