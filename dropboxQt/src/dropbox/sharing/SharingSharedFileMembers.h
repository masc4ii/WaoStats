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
    class SharedFileMembers{
        /**
            Shared file user, group, and invitee membership. Used for the
            results of :meth:`list_file_members` and
            :meth:`list_file_members_continue`, and used as part of the results
            for :meth:`list_file_members_batch`.

            field: users: The list of user members of the shared file.
            field: groups: The list of group members of the shared file.
            field: invitees: The list of invited members of a file, but have not
                logged in and claimed this.
            field: cursor: Present if there are additional shared file members
                that have not been returned yet. Pass the cursor into
                :meth:`list_file_members_continue` to list additional members.
        */

    public:
        SharedFileMembers(){};

        SharedFileMembers(const std::list <UserMembershipInfo>& arg){ m_users = arg; };
        virtual ~SharedFileMembers(){};

    public:
            /**
                The list of user members of the shared file.
            */
        const std::list <UserMembershipInfo>& users()const{return m_users;};
        SharedFileMembers& setUsers(const std::list <UserMembershipInfo>& arg){m_users=arg;return *this;};

            /**
                The list of group members of the shared file.
            */
        const std::list <GroupMembershipInfo>& groups()const{return m_groups;};
        SharedFileMembers& setGroups(const std::list <GroupMembershipInfo>& arg){m_groups=arg;return *this;};

            /**
                The list of invited members of a file, but have not logged in
                and claimed this.
            */
        const std::list <InviteeMembershipInfo>& invitees()const{return m_invitees;};
        SharedFileMembers& setInvitees(const std::list <InviteeMembershipInfo>& arg){m_invitees=arg;return *this;};

            /**
                Present if there are additional shared file members that have
                not been returned yet. Pass the cursor into
                :meth:`list_file_members_continue` to list additional members.
            */
        QString cursor()const{return m_cursor;};
        SharedFileMembers& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFileMembers>  create(const QByteArray& data);
            static std::unique_ptr<SharedFileMembers>  create(const QJsonObject& js);
        };



    protected:
            /**
                The list of user members of the shared file.
            */
        std::list <UserMembershipInfo> m_users;

            /**
                The list of group members of the shared file.
            */
        std::list <GroupMembershipInfo> m_groups;

            /**
                The list of invited members of a file, but have not logged in
                and claimed this.
            */
        std::list <InviteeMembershipInfo> m_invitees;

            /**
                Present if there are additional shared file members that have
                not been returned yet. Pass the cursor into
                :meth:`list_file_members_continue` to list additional members.
            */
        QString m_cursor;

    };//SharedFileMembers

}//sharing
}//dropboxQt
