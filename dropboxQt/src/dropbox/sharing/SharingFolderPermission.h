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
#include "dropbox/sharing/SharingPermissionDeniedReason.h"

namespace dropboxQt{
namespace sharing{
    class FolderPermission{
        /**
            Whether the user is allowed to take the action on the shared folder.

            field: action: The action that the user may wish to take on the
                folder.
            field: allow: True if the user is allowed to take the action.
            field: reason: The reason why the user is denied the permission. Not
                present if the action is allowed, or if no reason is available.
        */

    public:
        FolderPermission(){};

        FolderPermission(const FolderAction& arg){ m_action = arg; };
        virtual ~FolderPermission(){};

    public:
            /**
                The action that the user may wish to take on the folder.
            */
        const FolderAction& action()const{return m_action;};
        FolderPermission& setAction(const FolderAction& arg){m_action=arg;return *this;};

            /**
                True if the user is allowed to take the action.
            */
        bool allow()const{return m_allow;};
        FolderPermission& setAllow(const bool& arg){m_allow=arg;return *this;};

            /**
                The reason why the user is denied the permission. Not present if
                the action is allowed, or if no reason is available.
            */
        const PermissionDeniedReason& reason()const{return m_reason;};
        FolderPermission& setReason(const PermissionDeniedReason& arg){m_reason=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FolderPermission>  create(const QByteArray& data);
            static std::unique_ptr<FolderPermission>  create(const QJsonObject& js);
        };



    protected:
            /**
                The action that the user may wish to take on the folder.
            */
        FolderAction m_action;

            /**
                True if the user is allowed to take the action.
            */
        bool m_allow;

            /**
                The reason why the user is denied the permission. Not present if
                the action is allowed, or if no reason is available.
            */
        PermissionDeniedReason m_reason;

    };//FolderPermission

}//sharing
}//dropboxQt
