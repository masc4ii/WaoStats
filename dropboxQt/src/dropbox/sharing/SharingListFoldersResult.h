/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFolderMetadata.h"

namespace dropboxQt{
namespace sharing{
    class ListFoldersResult{
        /**
            Result for :meth:`list_folders` or :meth:`list_mountable_folders`,
            depending on which endpoint was requested. Unmounted shared folders
            can be identified by the absence of
            ``SharedFolderMetadata.path_lower``.

            field: entries: List of all shared folders the authenticated user
                has access to.
            field: cursor: Present if there are additional shared folders that
                have not been returned yet. Pass the cursor into the
                corresponding continue endpoint (either
                :meth:`list_folders_continue` or
                :meth:`list_mountable_folders_continue`) to list additional
                folders.
        */

    public:
        ListFoldersResult(){};

        ListFoldersResult(const std::list <SharedFolderMetadata>& arg){ m_entries = arg; };
        virtual ~ListFoldersResult(){};

    public:
            /**
                List of all shared folders the authenticated user has access to.
            */
        const std::list <SharedFolderMetadata>& entries()const{return m_entries;};

            /**
                Present if there are additional shared folders that have not
                been returned yet. Pass the cursor into the corresponding
                continue endpoint (either :meth:`list_folders_continue` or
                :meth:`list_mountable_folders_continue`) to list additional
                folders.
            */
        QString cursor()const{return m_cursor;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFoldersResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFoldersResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of all shared folders the authenticated user has access to.
            */
        std::list <SharedFolderMetadata> m_entries;

            /**
                Present if there are additional shared folders that have not
                been returned yet. Pass the cursor into the corresponding
                continue endpoint (either :meth:`list_folders_continue` or
                :meth:`list_mountable_folders_continue`) to list additional
                folders.
            */
        QString m_cursor;

    };//ListFoldersResult

}//sharing
}//dropboxQt
