/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMemberPolicy.h"
#include "dropbox/sharing/SharingAclUpdatePolicy.h"
#include "dropbox/sharing/SharingSharedLinkPolicy.h"

namespace dropboxQt{
namespace sharing{
    class FolderPolicy{
        /**
            A set of policies governing membership and privileges for a shared
            folder.

            field: member_policy: Who can be a member of this shared folder, as
                set on the folder itself. The effective policy may differ from
                this value if the team-wide policy is more restrictive. Present
                only if the folder is owned by a team.
            field: resolved_member_policy: Who can be a member of this shared
                folder, taking into account both the folder and the team-wide
                policy. This value may differ from that of member_policy if the
                team-wide policy is more restrictive than the folder policy.
                Present only if the folder is owned by a team.
            field: acl_update_policy: Who can add and remove members from this
                shared folder.
            field: shared_link_policy: Who links can be shared with.
        */

    public:
        FolderPolicy(){};

        FolderPolicy(const MemberPolicy& arg){ m_member_policy = arg; };
        virtual ~FolderPolicy(){};

    public:
            /**
                Who can be a member of this shared folder, as set on the folder
                itself. The effective policy may differ from this value if the
                team-wide policy is more restrictive. Present only if the folder
                is owned by a team.
            */
        const MemberPolicy& memberPolicy()const{return m_member_policy;};
        FolderPolicy& setMemberpolicy(const MemberPolicy& arg){m_member_policy=arg;return *this;};

            /**
                Who can be a member of this shared folder, taking into account
                both the folder and the team-wide policy. This value may differ
                from that of member_policy if the team-wide policy is more
                restrictive than the folder policy. Present only if the folder
                is owned by a team.
            */
        const MemberPolicy& resolvedMemberPolicy()const{return m_resolved_member_policy;};
        FolderPolicy& setResolvedmemberpolicy(const MemberPolicy& arg){m_resolved_member_policy=arg;return *this;};

            /**
                Who can add and remove members from this shared folder.
            */
        const AclUpdatePolicy& aclUpdatePolicy()const{return m_acl_update_policy;};
        FolderPolicy& setAclupdatepolicy(const AclUpdatePolicy& arg){m_acl_update_policy=arg;return *this;};

            /**
                Who links can be shared with.
            */
        const SharedLinkPolicy& sharedLinkPolicy()const{return m_shared_link_policy;};
        FolderPolicy& setSharedlinkpolicy(const SharedLinkPolicy& arg){m_shared_link_policy=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FolderPolicy>  create(const QByteArray& data);
            static std::unique_ptr<FolderPolicy>  create(const QJsonObject& js);
        };



    protected:
            /**
                Who can be a member of this shared folder, as set on the folder
                itself. The effective policy may differ from this value if the
                team-wide policy is more restrictive. Present only if the folder
                is owned by a team.
            */
        MemberPolicy m_member_policy;

            /**
                Who can be a member of this shared folder, taking into account
                both the folder and the team-wide policy. This value may differ
                from that of member_policy if the team-wide policy is more
                restrictive than the folder policy. Present only if the folder
                is owned by a team.
            */
        MemberPolicy m_resolved_member_policy;

            /**
                Who can add and remove members from this shared folder.
            */
        AclUpdatePolicy m_acl_update_policy;

            /**
                Who links can be shared with.
            */
        SharedLinkPolicy m_shared_link_policy;

    };//FolderPolicy

}//sharing
}//dropboxQt
