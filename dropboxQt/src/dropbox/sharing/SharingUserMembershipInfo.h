/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMembershipInfo.h"
#include "dropbox/sharing/SharingUserInfo.h"

namespace dropboxQt{
namespace sharing{
    class UserMembershipInfo : public MembershipInfo{
        /**
            The information about a user member of the shared content.

            field: user: The account information for the membership user.
        */

    public:
        UserMembershipInfo(){};

        UserMembershipInfo(const UserInfo& arg){ m_user = arg; };
        virtual ~UserMembershipInfo(){};

    public:
            /**
                The account information for the membership user.
            */
        const UserInfo& user()const{return m_user;};
        UserMembershipInfo& setUser(const UserInfo& arg){m_user=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UserMembershipInfo>  create(const QByteArray& data);
            static std::unique_ptr<UserMembershipInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                The account information for the membership user.
            */
        UserInfo m_user;

    };//UserMembershipInfo

}//sharing
}//dropboxQt
