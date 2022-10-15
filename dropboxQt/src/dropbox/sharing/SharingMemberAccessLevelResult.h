/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingAccessLevel.h"
#include "dropbox/sharing/SharingParentFolderAccessInfo.h"

namespace dropboxQt{
namespace sharing{
    class MemberAccessLevelResult{
        /**
            Contains information about a member's access level to content after
            an operation.

            field: access_level: The member still has this level of access to
                the content through a parent folder.
            field: warning: A localized string with additional information about
                why the user has this access level to the content.
            field: access_details: The parent folders that a member has access
                to. The field is present if the user has access to the first
                parent folder where the member gains access.
        */

    public:
        MemberAccessLevelResult(){};

        MemberAccessLevelResult(const AccessLevel& arg){ m_access_level = arg; };
        virtual ~MemberAccessLevelResult(){};

    public:
            /**
                The member still has this level of access to the content through
                a parent folder.
            */
        const AccessLevel& accessLevel()const{return m_access_level;};

            /**
                A localized string with additional information about why the
                user has this access level to the content.
            */
        QString warning()const{return m_warning;};

            /**
                The parent folders that a member has access to. The field is
                present if the user has access to the first parent folder where
                the member gains access.
            */
        const std::list <ParentFolderAccessInfo>& accessDetails()const{return m_access_details;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberAccessLevelResult>  create(const QByteArray& data);
            static std::unique_ptr<MemberAccessLevelResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                The member still has this level of access to the content through
                a parent folder.
            */
        AccessLevel m_access_level;

            /**
                A localized string with additional information about why the
                user has this access level to the content.
            */
        QString m_warning;

            /**
                The parent folders that a member has access to. The field is
                present if the user has access to the first parent folder where
                the member gains access.
            */
        std::list <ParentFolderAccessInfo> m_access_details;

    };//MemberAccessLevelResult

}//sharing
}//dropboxQt
