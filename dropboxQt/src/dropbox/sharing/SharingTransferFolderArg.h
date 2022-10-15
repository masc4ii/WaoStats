/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class TransferFolderArg{
        /**
            field: shared_folder_id: The ID for the shared folder.
            field: to_dropbox_id: A account or team member ID to transfer
                ownership to.
        */

    public:
        TransferFolderArg(){};

        TransferFolderArg(const QString& arg){ m_shared_folder_id = arg; };
        virtual ~TransferFolderArg(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        TransferFolderArg& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                A account or team member ID to transfer ownership to.
            */
        QString toDropboxId()const{return m_to_dropbox_id;};
        TransferFolderArg& setTodropboxid(const QString& arg){m_to_dropbox_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<TransferFolderArg>  create(const QByteArray& data);
            static std::unique_ptr<TransferFolderArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

            /**
                A account or team member ID to transfer ownership to.
            */
        QString m_to_dropbox_id;

    };//TransferFolderArg

}//sharing
}//dropboxQt
