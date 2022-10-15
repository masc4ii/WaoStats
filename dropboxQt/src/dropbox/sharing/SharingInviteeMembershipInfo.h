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
#include "dropbox/sharing/SharingInviteeInfo.h"
#include "dropbox/sharing/SharingUserInfo.h"

namespace dropboxQt{
namespace sharing{
    class InviteeMembershipInfo : public MembershipInfo{
        /**
            Information about an invited member of a shared content.

            field: invitee: Recipient of the invitation.
            field: user: The user this invitation is tied to, if available.
        */

    public:
        InviteeMembershipInfo(){};

        InviteeMembershipInfo(const InviteeInfo& arg){ m_invitee = arg; };
        virtual ~InviteeMembershipInfo(){};

    public:
            /**
                Recipient of the invitation.
            */
        const InviteeInfo& invitee()const{return m_invitee;};
        InviteeMembershipInfo& setInvitee(const InviteeInfo& arg){m_invitee=arg;return *this;};

            /**
                The user this invitation is tied to, if available.
            */
        const UserInfo& user()const{return m_user;};
        InviteeMembershipInfo& setUser(const UserInfo& arg){m_user=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<InviteeMembershipInfo>  create(const QByteArray& data);
            static std::unique_ptr<InviteeMembershipInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                Recipient of the invitation.
            */
        InviteeInfo m_invitee;

            /**
                The user this invitation is tied to, if available.
            */
        UserInfo m_user;

    };//InviteeMembershipInfo

}//sharing
}//dropboxQt
