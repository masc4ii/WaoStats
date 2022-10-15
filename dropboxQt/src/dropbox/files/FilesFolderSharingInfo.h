/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesSharingInfo.h"

namespace dropboxQt{
namespace files{
    class FolderSharingInfo : public SharingInfo{
        /**
            Sharing info for a folder which is contained in a shared folder or
            is a shared folder mount point.

            field: parent_shared_folder_id: Set if the folder is contained by a
                shared folder.
            field: shared_folder_id: If this folder is a shared folder mount
                point, the ID of the shared folder mounted at this location.
            field: traverse_only: Specifies that the folder can only be
                traversed and the user can only see a limited subset of the
                contents of this folder because they don't have read access to
                this folder. They do, however, have access to some sub folder.
            field: no_access: Specifies that the folder cannot be accessed by
                the user
        */

    public:
        FolderSharingInfo():
        m_traverse_only(false)
        ,m_no_access(false)
        {};

        FolderSharingInfo(const QString& arg):
        m_traverse_only(false)
        ,m_no_access(false)
        { m_parent_shared_folder_id = arg; };
        virtual ~FolderSharingInfo(){};

    public:
            /**
                Set if the folder is contained by a shared folder.
            */
        QString parentSharedFolderId()const{return m_parent_shared_folder_id;};
        FolderSharingInfo& setParentsharedfolderid(const QString& arg){m_parent_shared_folder_id=arg;return *this;};

            /**
                If this folder is a shared folder mount point, the ID of the
                shared folder mounted at this location.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        FolderSharingInfo& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                Specifies that the folder can only be traversed and the user can
                only see a limited subset of the contents of this folder because
                they don't have read access to this folder. They do, however,
                have access to some sub folder.
            */
        bool traverseOnly()const{return m_traverse_only;};
        FolderSharingInfo& setTraverseonly(const bool& arg){m_traverse_only=arg;return *this;};

            /**
                Specifies that the folder cannot be accessed by the user
            */
        bool noAccess()const{return m_no_access;};
        FolderSharingInfo& setNoaccess(const bool& arg){m_no_access=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FolderSharingInfo>  create(const QByteArray& data);
            static std::unique_ptr<FolderSharingInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                Set if the folder is contained by a shared folder.
            */
        QString m_parent_shared_folder_id;

            /**
                If this folder is a shared folder mount point, the ID of the
                shared folder mounted at this location.
            */
        QString m_shared_folder_id;

            /**
                Specifies that the folder can only be traversed and the user can
                only see a limited subset of the contents of this folder because
                they don't have read access to this folder. They do, however,
                have access to some sub folder.
            */
        bool m_traverse_only;

            /**
                Specifies that the folder cannot be accessed by the user
            */
        bool m_no_access;

    };//FolderSharingInfo

}//files
}//dropboxQt
