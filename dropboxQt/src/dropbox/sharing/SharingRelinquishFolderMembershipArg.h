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
    class RelinquishFolderMembershipArg{
        /**
            field: shared_folder_id: The ID for the shared folder.
            field: leave_a_copy: Keep a copy of the folder's contents upon
                relinquishing membership.
        */

    public:
        RelinquishFolderMembershipArg():
        m_leave_a_copy(false)
        {};

        RelinquishFolderMembershipArg(const QString& arg):
        m_leave_a_copy(false)
        { m_shared_folder_id = arg; };
        virtual ~RelinquishFolderMembershipArg(){};

    public:
            /**
                The ID for the shared folder.
            */
        QString sharedFolderId()const{return m_shared_folder_id;};
        RelinquishFolderMembershipArg& setSharedfolderid(const QString& arg){m_shared_folder_id=arg;return *this;};

            /**
                Keep a copy of the folder's contents upon relinquishing
                membership.
            */
        bool leaveACopy()const{return m_leave_a_copy;};
        RelinquishFolderMembershipArg& setLeaveacopy(const bool& arg){m_leave_a_copy=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RelinquishFolderMembershipArg>  create(const QByteArray& data);
            static std::unique_ptr<RelinquishFolderMembershipArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The ID for the shared folder.
            */
        QString m_shared_folder_id;

            /**
                Keep a copy of the folder's contents upon relinquishing
                membership.
            */
        bool m_leave_a_copy;

    };//RelinquishFolderMembershipArg

}//sharing
}//dropboxQt
