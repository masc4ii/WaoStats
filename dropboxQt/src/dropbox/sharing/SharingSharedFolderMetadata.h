/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFolderMetadataBase.h"
#include "dropbox/sharing/SharingFolderPermission.h"

namespace dropboxQt{
namespace sharing{
    class SharedFolderMetadata : public SharedFolderMetadataBase{
        /**
            The metadata which includes basic information about the shared
            folder.

            field: path_lower: The lower-cased full path of this shared folder.
                Absent for unmounted folders.
            field: name: The name of the this shared folder.
            field: shared_folder_id: The ID of the shared folder.
            field: permissions: Actions the current user may perform on the
                folder and its contents. The set of permissions corresponds to
                the FolderActions in the request.
            field: time_invited: Timestamp indicating when the current user was
                invited to this shared folder.
            field: preview_url: URL for displaying a web preview of the shared
                folder.
        */

    public:
        SharedFolderMetadata(){};

        SharedFolderMetadata(const QString& arg){ m_path_lower = arg; };
        virtual ~SharedFolderMetadata(){};

    public:
            /**
                The lower-cased full path of this shared folder. Absent for
                unmounted folders.
            */
        QString pathLower()const{return m_path_lower;};
        SharedFolderMetadata& setPathlower(const QString& arg){m_path_lower=arg;return *this;};

            /**
                The name of the this shared folder.
            */
        QString name()const{return m_name;};
        SharedFolderMetadata& setName(const QString& arg){m_name=arg;return *this;};

            /**
                The ID of the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        SharedFolderMetadata& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                Actions the current user may perform on the folder and its
                contents. The set of permissions corresponds to the
                FolderActions in the request.
            */
        const std::list <FolderPermission>& permissions()const{return m_permissions;};
        SharedFolderMetadata& setPermissions(const std::list <FolderPermission>& arg){m_permissions=arg;return *this;};

            /**
                Timestamp indicating when the current user was invited to this
                shared folder.
            */
        QDateTime timeInvited()const{return m_time_invited;};
        SharedFolderMetadata& setTimeinvited(const QDateTime& arg){m_time_invited=arg;return *this;};

            /**
                URL for displaying a web preview of the shared folder.
            */
        QString previewUrl()const{return m_preview_url;};
        SharedFolderMetadata& setPreviewurl(const QString& arg){m_preview_url=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderMetadata>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderMetadata>  create(const QJsonObject& js);
        };



    protected:
            /**
                The lower-cased full path of this shared folder. Absent for
                unmounted folders.
            */
        QString m_path_lower;

            /**
                The name of the this shared folder.
            */
        QString m_name;

            /**
                The ID of the shared folder.
            */
        QString m_shared_folder_id;

            /**
                Actions the current user may perform on the folder and its
                contents. The set of permissions corresponds to the
                FolderActions in the request.
            */
        std::list <FolderPermission> m_permissions;

            /**
                Timestamp indicating when the current user was invited to this
                shared folder.
            */
        QDateTime m_time_invited;

            /**
                URL for displaying a web preview of the shared folder.
            */
        QString m_preview_url;

    };//SharedFolderMetadata

}//sharing
}//dropboxQt
