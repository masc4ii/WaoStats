/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamUserSelectorArg.h"
#include "dropbox/team/TeamGroupAccessType.h"

namespace dropboxQt{
namespace team{
    class MemberAccess{
        /**
            Specify access type a member should have when joined to a group.

            field: user: Identity of a user.
            field: access_type: Access type.
        */

    public:
        MemberAccess(){};

        MemberAccess(const UserSelectorArg& arg){ m_user = arg; };
        virtual ~MemberAccess(){};

    public:
            /**
                Identity of a user.
            */
        const UserSelectorArg& user()const{return m_user;};
        MemberAccess& setUser(const UserSelectorArg& arg){m_user=arg;return *this;};

            /**
                Access type.
            */
        const GroupAccessType& accessType()const{return m_access_type;};
        MemberAccess& setAccesstype(const GroupAccessType& arg){m_access_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberAccess>  create(const QByteArray& data);
            static std::unique_ptr<MemberAccess>  create(const QJsonObject& js);
        };



    protected:
            /**
                Identity of a user.
            */
        UserSelectorArg m_user;

            /**
                Access type.
            */
        GroupAccessType m_access_type;

    };//MemberAccess

}//team
}//dropboxQt
