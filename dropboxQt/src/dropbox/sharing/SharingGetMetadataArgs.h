/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingFolderAction.h"

namespace dropboxQt{
namespace sharing{
    class GetMetadataArgs{
        /**
            field: shared_folder_id: The ID for the shared folder.
            field: actions: This is a list indicating whether the returned
                folder data will include a boolean value
                ``FolderPermission.allow`` that describes whether the current
                user can perform the  FolderAction on the folder.
        */

    public:
        GetMetadataArgs(){};

        GetMetadataArgs(const QString& arg){ m_shared_folder_id = arg; };
        virtual ~GetMetadataArgs(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        GetMetadataArgs& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                This is a list indicating whether the returned folder data will
                include a boolean value  ``FolderPermission.allow`` that
                describes whether the current user can perform the  FolderAction
                on the folder.
            */
        const std::list <FolderAction>& actions()const{return m_actions;};
        GetMetadataArgs& setActions(const std::list <FolderAction>& arg){m_actions=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetMetadataArgs>  create(const QByteArray& data);
            static std::unique_ptr<GetMetadataArgs>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

            /**
                This is a list indicating whether the returned folder data will
                include a boolean value  ``FolderPermission.allow`` that
                describes whether the current user can perform the  FolderAction
                on the folder.
            */
        std::list <FolderAction> m_actions;

    };//GetMetadataArgs

}//sharing
}//dropboxQt
