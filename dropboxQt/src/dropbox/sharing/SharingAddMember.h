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
    class AddMember{
        /**
            The member and type of access the member should have when added to a
            shared folder.

            field: member: The member to add to the shared folder.
            field: access_level: The access level to grant ``member`` to the
                shared folder.  ``AccessLevel.owner`` is disallowed.
        */

    public:
        AddMember():
        m_access_level(AccessLevel::AccessLevel_VIEWER)
        {};

        AddMember(const MemberSelector& arg):
        m_access_level(AccessLevel::AccessLevel_VIEWER)
        { m_member = arg; };
        virtual ~AddMember(){};

    public:
            /**
                The member to add to the shared folder.
            */
        const MemberSelector& member()const{return m_member;};
        AddMember& setMember(const MemberSelector& arg){m_member=arg;return *this;};

            /**
                The access level to grant ``member`` to the shared folder.
                ``AccessLevel.owner`` is disallowed.
            */
        const AccessLevel& accessLevel()const{return m_access_level;};
        AddMember& setAccesslevel(const AccessLevel& arg){m_access_level=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AddMember>  create(const QByteArray& data);
            static std::unique_ptr<AddMember>  create(const QJsonObject& js);
        };



    protected:
            /**
                The member to add to the shared folder.
            */
        MemberSelector m_member;

            /**
                The access level to grant ``member`` to the shared folder.
                ``AccessLevel.owner`` is disallowed.
            */
        AccessLevel m_access_level;

    };//AddMember

}//sharing
}//dropboxQt
