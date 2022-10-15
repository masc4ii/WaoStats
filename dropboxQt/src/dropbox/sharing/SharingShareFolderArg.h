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
    class ShareFolderArg{
        /**
            field: path: The path to the folder to share. If it does not exist,
                then a new one is created.
            field: member_policy: Who can be a member of this shared folder.
                Only applicable if the current user is on a team.
            field: acl_update_policy: Who can add and remove members of this
                shared folder.
            field: shared_link_policy: The policy to apply to shared links
                created for content inside this shared folder.  The current user
                must be on a team to set this policy to
                ``SharedLinkPolicy.members``.
            field: force_async: Whether to force the share to happen
                asynchronously.
        */

    public:
        ShareFolderArg():
        m_member_policy(MemberPolicy::MemberPolicy_ANYONE)
        ,m_acl_update_policy(AclUpdatePolicy::AclUpdatePolicy_OWNER)
        ,m_shared_link_policy(SharedLinkPolicy::SharedLinkPolicy_ANYONE)
        ,m_force_async(false)
        {};

        ShareFolderArg(const QString& arg):
        m_member_policy(MemberPolicy::MemberPolicy_ANYONE)
        ,m_acl_update_policy(AclUpdatePolicy::AclUpdatePolicy_OWNER)
        ,m_shared_link_policy(SharedLinkPolicy::SharedLinkPolicy_ANYONE)
        ,m_force_async(false)
        { m_path = arg; };
        virtual ~ShareFolderArg(){};

    public:
            /**
                The path to the folder to share. If it does not exist, then a
                new one is created.
            */
        QString path()const{return m_path;};
        ShareFolderArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                Who can be a member of this shared folder. Only applicable if
                the current user is on a team.
            */
        const MemberPolicy& memberPolicy()const{return m_member_policy;};
        ShareFolderArg& setMemberpolicy(const MemberPolicy& arg){m_member_policy=arg;return *this;};

            /**
                Who can add and remove members of this shared folder.
            */
        const AclUpdatePolicy& aclUpdatePolicy()const{return m_acl_update_policy;};
        ShareFolderArg& setAclupdatepolicy(const AclUpdatePolicy& arg){m_acl_update_policy=arg;return *this;};

            /**
                The policy to apply to shared links created for content inside
                this shared folder.  The current user must be on a team to set
                this policy to ``SharedLinkPolicy.members``.
            */
        const SharedLinkPolicy& sharedLinkPolicy()const{return m_shared_link_policy;};
        ShareFolderArg& setSharedlinkpolicy(const SharedLinkPolicy& arg){m_shared_link_policy=arg;return *this;};

            /**
                Whether to force the share to happen asynchronously.
            */
        bool forceAsync()const{return m_force_async;};
        ShareFolderArg& setForceasync(const bool& arg){m_force_async=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ShareFolderArg>  create(const QByteArray& data);
            static std::unique_ptr<ShareFolderArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The path to the folder to share. If it does not exist, then a
                new one is created.
            */
        QString m_path;

            /**
                Who can be a member of this shared folder. Only applicable if
                the current user is on a team.
            */
        MemberPolicy m_member_policy;

            /**
                Who can add and remove members of this shared folder.
            */
        AclUpdatePolicy m_acl_update_policy;

            /**
                The policy to apply to shared links created for content inside
                this shared folder.  The current user must be on a team to set
                this policy to ``SharedLinkPolicy.members``.
            */
        SharedLinkPolicy m_shared_link_policy;

            /**
                Whether to force the share to happen asynchronously.
            */
        bool m_force_async;

    };//ShareFolderArg

}//sharing
}//dropboxQt
