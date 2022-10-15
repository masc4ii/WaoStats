/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingFolderPolicy.h"
#include "dropbox/sharing/SharingFilePermission.h"
#include "dropbox/users/UsersTeam.h"

namespace dropboxQt{
namespace sharing{
    class SharedFileMetadata{
        /**
            Properties of the shared file.

            field: policy: Policies governing this shared file.
            field: permissions: The sharing permissions that requesting user has
                on this file. This corresponds to the entries given in
                ``GetFileMetadataBatchArg.actions`` or
                ``GetFileMetadataArg.actions``.
            field: owner_team: The team that owns the file. This field is not
                present if the file is not owned by a team.
            field: parent_shared_folder_id: The ID of the parent shared folder.
                This field is present only if the file is contained within a
                shared folder.
            field: preview_url: URL for displaying a web preview of the shared
                file.
            field: path_lower: The lower-case full path of this file. Absent for
                unmounted files.
            field: path_display: The cased path to be used for display purposes
                only. In rare instances the casing will not correctly match the
                user's filesystem, but this behavior will match the path
                provided in the Core API v1. Absent for unmounted files.
            field: name: The name of this file.
            field: id: The ID of the file.
            field: time_invited: Timestamp indicating when the current user was
                invited to this shared file. If the user was not invited to the
                shared file, the timestamp will indicate when the user was
                invited to the parent shared folder. This value may be absent.
        */

    public:
        SharedFileMetadata(){};

        SharedFileMetadata(const FolderPolicy& arg){ m_policy = arg; };
        virtual ~SharedFileMetadata(){};

    public:
            /**
                Policies governing this shared file.
            */
        const FolderPolicy& policy()const{return m_policy;};
        SharedFileMetadata& setPolicy(const FolderPolicy& arg){m_policy=arg;return *this;};

            /**
                The sharing permissions that requesting user has on this file.
                This corresponds to the entries given in
                ``GetFileMetadataBatchArg.actions`` or
                ``GetFileMetadataArg.actions``.
            */
        const std::list <FilePermission>& permissions()const{return m_permissions;};
        SharedFileMetadata& setPermissions(const std::list <FilePermission>& arg){m_permissions=arg;return *this;};

            /**
                The team that owns the file. This field is not present if the
                file is not owned by a team.
            */
        const users::Team& ownerTeam()const{return m_owner_team;};
        SharedFileMetadata& setOwnerteam(const users::Team& arg){m_owner_team=arg;return *this;};

            /**
                The ID of the parent shared folder. This field is present only
                if the file is contained within a shared folder.
            */
        QString parentSharedFolderId()const{return m_parent_shared_folder_id;};
        SharedFileMetadata& setParentsharedfolderid(const QString& arg){m_parent_shared_folder_id=arg;return *this;};

            /**
                URL for displaying a web preview of the shared file.
            */
        QString previewUrl()const{return m_preview_url;};
        SharedFileMetadata& setPreviewurl(const QString& arg){m_preview_url=arg;return *this;};

            /**
                The lower-case full path of this file. Absent for unmounted
                files.
            */
        QString pathLower()const{return m_path_lower;};
        SharedFileMetadata& setPathlower(const QString& arg){m_path_lower=arg;return *this;};

            /**
                The cased path to be used for display purposes only. In rare
                instances the casing will not correctly match the user's
                filesystem, but this behavior will match the path provided in
                the Core API v1. Absent for unmounted files.
            */
        QString pathDisplay()const{return m_path_display;};
        SharedFileMetadata& setPathdisplay(const QString& arg){m_path_display=arg;return *this;};

            /**
                The name of this file.
            */
        QString name()const{return m_name;};
        SharedFileMetadata& setName(const QString& arg){m_name=arg;return *this;};

            /**
                The ID of the file.
            */
        QString id()const{return m_id;};
        SharedFileMetadata& setId(const QString& arg){m_id=arg;return *this;};

            /**
                Timestamp indicating when the current user was invited to this
                shared file. If the user was not invited to the shared file, the
                timestamp will indicate when the user was invited to the parent
                shared folder. This value may be absent.
            */
        QDateTime timeInvited()const{return m_time_invited;};
        SharedFileMetadata& setTimeinvited(const QDateTime& arg){m_time_invited=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFileMetadata>  create(const QByteArray& data);
            static std::unique_ptr<SharedFileMetadata>  create(const QJsonObject& js);
        };



    protected:
            /**
                Policies governing this shared file.
            */
        FolderPolicy m_policy;

            /**
                The sharing permissions that requesting user has on this file.
                This corresponds to the entries given in
                ``GetFileMetadataBatchArg.actions`` or
                ``GetFileMetadataArg.actions``.
            */
        std::list <FilePermission> m_permissions;

            /**
                The team that owns the file. This field is not present if the
                file is not owned by a team.
            */
        users::Team m_owner_team;

            /**
                The ID of the parent shared folder. This field is present only
                if the file is contained within a shared folder.
            */
        QString m_parent_shared_folder_id;

            /**
                URL for displaying a web preview of the shared file.
            */
        QString m_preview_url;

            /**
                The lower-case full path of this file. Absent for unmounted
                files.
            */
        QString m_path_lower;

            /**
                The cased path to be used for display purposes only. In rare
                instances the casing will not correctly match the user's
                filesystem, but this behavior will match the path provided in
                the Core API v1. Absent for unmounted files.
            */
        QString m_path_display;

            /**
                The name of this file.
            */
        QString m_name;

            /**
                The ID of the file.
            */
        QString m_id;

            /**
                Timestamp indicating when the current user was invited to this
                shared file. If the user was not invited to the shared file, the
                timestamp will indicate when the user was invited to the parent
                shared folder. This value may be absent.
            */
        QDateTime m_time_invited;

    };//SharedFileMetadata

}//sharing
}//dropboxQt
