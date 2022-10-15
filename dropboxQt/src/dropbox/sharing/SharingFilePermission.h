/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingFileAction.h"
#include "dropbox/sharing/SharingPermissionDeniedReason.h"

namespace dropboxQt{
namespace sharing{
    class FilePermission{
        /**
            Whether the user is allowed to take the sharing action on the file.

            field: action: The action that the user may wish to take on the
                file.
            field: allow: True if the user is allowed to take the action.
            field: reason: The reason why the user is denied the permission. Not
                present if the action is allowed
        */

    public:
        FilePermission(){};

        FilePermission(const FileAction& arg){ m_action = arg; };
        virtual ~FilePermission(){};

    public:
            /**
                The action that the user may wish to take on the file.
            */
        const FileAction& action()const{return m_action;};
        FilePermission& setAction(const FileAction& arg){m_action=arg;return *this;};

            /**
                True if the user is allowed to take the action.
            */
        bool allow()const{return m_allow;};
        FilePermission& setAllow(const bool& arg){m_allow=arg;return *this;};

            /**
                The reason why the user is denied the permission. Not present if
                the action is allowed
            */
        const PermissionDeniedReason& reason()const{return m_reason;};
        FilePermission& setReason(const PermissionDeniedReason& arg){m_reason=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FilePermission>  create(const QByteArray& data);
            static std::unique_ptr<FilePermission>  create(const QJsonObject& js);
        };



    protected:
            /**
                The action that the user may wish to take on the file.
            */
        FileAction m_action;

            /**
                True if the user is allowed to take the action.
            */
        bool m_allow;

            /**
                The reason why the user is denied the permission. Not present if
                the action is allowed
            */
        PermissionDeniedReason m_reason;

    };//FilePermission

}//sharing
}//dropboxQt
