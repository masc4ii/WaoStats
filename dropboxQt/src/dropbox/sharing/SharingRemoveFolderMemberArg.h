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

namespace dropboxQt{
namespace sharing{
    class RemoveFolderMemberArg{
        /**
            field: shared_folder_id: The ID for the shared folder.
            field: member: The member to remove from the folder.
            field: leave_a_copy: If true, the removed user will keep their copy
                of the folder after it's unshared, assuming it was mounted.
                Otherwise, it will be removed from their Dropbox. Also, this
                must be set to false when kicking a group.
        */

    public:
        RemoveFolderMemberArg(){};

        RemoveFolderMemberArg(const QString& arg){ m_shared_folder_id = arg; };
        virtual ~RemoveFolderMemberArg(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        RemoveFolderMemberArg& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                The member to remove from the folder.
            */
        const MemberSelector& member()const{return m_member;};
        RemoveFolderMemberArg& setMember(const MemberSelector& arg){m_member=arg;return *this;};

            /**
                If true, the removed user will keep their copy of the folder
                after it's unshared, assuming it was mounted. Otherwise, it will
                be removed from their Dropbox. Also, this must be set to false
                when kicking a group.
            */
        bool leaveACopy()const{return m_leave_a_copy;};
        RemoveFolderMemberArg& setLeaveacopy(const bool& arg){m_leave_a_copy=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemoveFolderMemberArg>  create(const QByteArray& data);
            static std::unique_ptr<RemoveFolderMemberArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

            /**
                The member to remove from the folder.
            */
        MemberSelector m_member;

            /**
                If true, the removed user will keep their copy of the folder
                after it's unshared, assuming it was mounted. Otherwise, it will
                be removed from their Dropbox. Also, this must be set to false
                when kicking a group.
            */
        bool m_leave_a_copy;

    };//RemoveFolderMemberArg

}//sharing
}//dropboxQt
