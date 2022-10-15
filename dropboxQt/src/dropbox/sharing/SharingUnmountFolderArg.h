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
    class UnmountFolderArg{
        /**
            field: shared_folder_id: The ID for the shared folder.
        */

    public:
        UnmountFolderArg(){};

        UnmountFolderArg(const QString& arg){ m_shared_folder_id = arg; };
        virtual ~UnmountFolderArg(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        UnmountFolderArg& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UnmountFolderArg>  create(const QByteArray& data);
            static std::unique_ptr<UnmountFolderArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

    };//UnmountFolderArg

}//sharing
}//dropboxQt
