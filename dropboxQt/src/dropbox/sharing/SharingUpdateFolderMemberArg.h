/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMemberSelector.h"
#include "dropbox/sharing/SharingAccessLevel.h"

namespace dropboxQt{
namespace sharing{
    class UpdateFolderMemberArg{
        /**
            field: shared_folder_id: The ID for the shared folder.
            field: member: The member of the shared folder to update.  Only the
                ``MemberSelector.dropbox_id`` may be set at this time.
            field: access_level: The new access level for ``member``.
                ``AccessLevel.owner`` is disallowed.
        */

    public:
        UpdateFolderMemberArg(){};

        UpdateFolderMemberArg(const QString& arg){ m_shared_folder_id = arg; };
        virtual ~UpdateFolderMemberArg(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        UpdateFolderMemberArg& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                The member of the shared folder to update.  Only the
                ``MemberSelector.dropbox_id`` may be set at this time.
            */
        const MemberSelector& member()const{return m_member;};
        UpdateFolderMemberArg& setMember(const MemberSelector& arg){m_member=arg;return *this;};

            /**
                The new access level for ``member``. ``AccessLevel.owner`` is
                disallowed.
            */
        const AccessLevel& accessLevel()const{return m_access_level;};
        UpdateFolderMemberArg& setAccesslevel(const AccessLevel& arg){m_access_level=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UpdateFolderMemberArg>  create(const QByteArray& data);
            static std::unique_ptr<UpdateFolderMemberArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

            /**
                The member of the shared folder to update.  Only the
                ``MemberSelector.dropbox_id`` may be set at this time.
            */
        MemberSelector m_member;

            /**
                The new access level for ``member``. ``AccessLevel.owner`` is
                disallowed.
            */
        AccessLevel m_access_level;

    };//UpdateFolderMemberArg

}//sharing
}//dropboxQt
