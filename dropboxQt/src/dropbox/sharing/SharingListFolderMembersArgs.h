/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingListFolderMembersCursorArg.h"

namespace dropboxQt{
namespace sharing{
    class ListFolderMembersArgs : public ListFolderMembersCursorArg{
        /**
            field: shared_folder_id: The ID for the shared folder.
        */

    public:
        ListFolderMembersArgs(){};

        ListFolderMembersArgs(const QString& arg){ m_shared_folder_id = arg; };
        virtual ~ListFolderMembersArgs(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        ListFolderMembersArgs& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderMembersArgs>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderMembersArgs>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

    };//ListFolderMembersArgs

}//sharing
}//dropboxQt
