/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingAccessLevel.h"
#include "dropbox/sharing/SharingFolderPolicy.h"
#include "dropbox/users/UsersTeam.h"

namespace dropboxQt{
namespace sharing{
    class SharedFolderMetadataBase{
        /**
            Properties of the shared folder.

            field: access_type: The current user's access level for this shared
                folder.
            field: is_team_folder: Whether this folder is a `team folder
                <https://www.dropbox.com/en/help/986>`_.
            field: policy: Policies governing this shared folder.
            field: owner_team: The team that owns the folder. This field is not
                present if the folder is not owned by a team.
            field: parent_shared_folder_id: The ID of the parent shared folder.
                This field is present only if the folder is contained within
                another shared folder.
        */

    public:
        SharedFolderMetadataBase(){};

        SharedFolderMetadataBase(const AccessLevel& arg){ m_access_type = arg; };
        virtual ~SharedFolderMetadataBase(){};

    public:
            /**
                The current user's access level for this shared folder.
            */
        const AccessLevel& accessType()const{return m_access_type;};
        SharedFolderMetadataBase& setAccesstype(const AccessLevel& arg){m_access_type=arg;return *this;};

            /**
                Whether this folder is a `team folder
                <https://www.dropbox.com/en/help/986>`_.
            */
        bool isTeamFolder()const{return m_is_team_folder;};
        SharedFolderMetadataBase& setIsteamfolder(const bool& arg){m_is_team_folder=arg;return *this;};

            /**
                Policies governing this shared folder.
            */
        const FolderPolicy& policy()const{return m_policy;};
        SharedFolderMetadataBase& setPolicy(const FolderPolicy& arg){m_policy=arg;return *this;};

            /**
                The team that owns the folder. This field is not present if the
                folder is not owned by a team.
            */
        const users::Team& ownerTeam()const{return m_owner_team;};
        SharedFolderMetadataBase& setOwnerteam(const users::Team& arg){m_owner_team=arg;return *this;};

            /**
                The ID of the parent shared folder. This field is present only
                if the folder is contained within another shared folder.
            */
        QString parentSharedFolderId()const{return m_parent_shared_folder_id;};
        SharedFolderMetadataBase& setParentsharedfolderid(const QString& arg){m_parent_shared_folder_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderMetadataBase>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderMetadataBase>  create(const QJsonObject& js);
        };



    protected:
            /**
                The current user's access level for this shared folder.
            */
        AccessLevel m_access_type;

            /**
                Whether this folder is a `team folder
                <https://www.dropbox.com/en/help/986>`_.
            */
        bool m_is_team_folder;

            /**
                Policies governing this shared folder.
            */
        FolderPolicy m_policy;

            /**
                The team that owns the folder. This field is not present if the
                folder is not owned by a team.
            */
        users::Team m_owner_team;

            /**
                The ID of the parent shared folder. This field is present only
                if the folder is contained within another shared folder.
            */
        QString m_parent_shared_folder_id;

    };//SharedFolderMetadataBase

}//sharing
}//dropboxQt
