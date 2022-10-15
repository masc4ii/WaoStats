/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesMetadata.h"
#include "dropbox/files/FilesFolderSharingInfo.h"
#include "dropbox/properties/PropertiesPropertyGroup.h"

namespace dropboxQt{
namespace files{
    class FolderMetadata : public Metadata{
        /**
            field: id: A unique identifier for the folder.
            field: shared_folder_id: Deprecated. Please use ``sharing_info``
                instead.
            field: sharing_info: Set if the folder is contained in a shared
                folder or is a shared folder mount point.
            field: property_groups: Additional information if the file has
                custom properties with the property template specified.
        */

    public:
        FolderMetadata(){};

        FolderMetadata(const QString& arg){ m_id = arg; };
        virtual ~FolderMetadata(){};

    public:
            /**
                A unique identifier for the folder.
            */
        QString id()const{return m_id;};
        FolderMetadata& setId(const QString& arg){m_id=arg;return *this;};

            /**
                Deprecated. Please use ``sharing_info`` instead.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        FolderMetadata& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                Set if the folder is contained in a shared folder or is a shared
                folder mount point.
            */
        const FolderSharingInfo& sharingInfo()const{return m_sharing_info;};
        FolderMetadata& setSharinginfo(const FolderSharingInfo& arg){m_sharing_info=arg;return *this;};

            /**
                Additional information if the file has custom properties with
                the property template specified.
            */
        const std::list <properties::PropertyGroup>& propertyGroups()const{return m_property_groups;};
        FolderMetadata& setPropertygroups(const std::list <properties::PropertyGroup>& arg){m_property_groups=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FolderMetadata>  create(const QByteArray& data);
            static std::unique_ptr<FolderMetadata>  create(const QJsonObject& js);
        };



    protected:
            /**
                A unique identifier for the folder.
            */
        QString m_id;

            /**
                Deprecated. Please use ``sharing_info`` instead.
            */
        QString m_shared_folder_id;

            /**
                Set if the folder is contained in a shared folder or is a shared
                folder mount point.
            */
        FolderSharingInfo m_sharing_info;

            /**
                Additional information if the file has custom properties with
                the property template specified.
            */
        std::list <properties::PropertyGroup> m_property_groups;

    };//FolderMetadata

}//files
}//dropboxQt
