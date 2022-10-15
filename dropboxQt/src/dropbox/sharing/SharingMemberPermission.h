/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMemberAction.h"
#include "dropbox/sharing/SharingPermissionDeniedReason.h"

namespace dropboxQt{
namespace sharing{
    class MemberPermission{
        /**
            Whether the user is allowed to take the action on the associated
            member.

            field: action: The action that the user may wish to take on the
                member.
            field: allow: True if the user is allowed to take the action.
            field: reason: The reason why the user is denied the permission. Not
                present if the action is allowed
        */

    public:
        MemberPermission(){};

        MemberPermission(const MemberAction& arg){ m_action = arg; };
        virtual ~MemberPermission(){};

    public:
            /**
                The action that the user may wish to take on the member.
            */
        const MemberAction& action()const{return m_action;};
        MemberPermission& setAction(const MemberAction& arg){m_action=arg;return *this;};

            /**
                True if the user is allowed to take the action.
            */
        bool allow()const{return m_allow;};
        MemberPermission& setAllow(const bool& arg){m_allow=arg;return *this;};

            /**
                The reason why the user is denied the permission. Not present if
                the action is allowed
            */
        const PermissionDeniedReason& reason()const{return m_reason;};
        MemberPermission& setReason(const PermissionDeniedReason& arg){m_reason=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberPermission>  create(const QByteArray& data);
            static std::unique_ptr<MemberPermission>  create(const QJsonObject& js);
        };



    protected:
            /**
                The action that the user may wish to take on the member.
            */
        MemberAction m_action;

            /**
                True if the user is allowed to take the action.
            */
        bool m_allow;

            /**
                The reason why the user is denied the permission. Not present if
                the action is allowed
            */
        PermissionDeniedReason m_reason;

    };//MemberPermission

}//sharing
}//dropboxQt
