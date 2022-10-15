/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMembersDeactivateArg.h"
#include "dropbox/team/TeamUserSelectorArg.h"

namespace dropboxQt{
namespace team{
    class MembersRemoveArg : public MembersDeactivateArg{
        /**
            field: transfer_dest_id: If provided, files from the deleted member
                account will be transferred to this user.
            field: transfer_admin_id: If provided, errors during the transfer
                process will be sent via email to this user. If the
                transfer_dest_id argument was provided, then this argument must
                be provided as well.
            field: keep_account: Downgrade the member to a Basic account. The
                user will retain the email address associated with their Dropbox
                account and data in their account that is not restricted to team
                members.
        */

    public:
        MembersRemoveArg():
        m_keep_account(false)
        {};

        MembersRemoveArg(const UserSelectorArg& arg):
        m_keep_account(false)
        { m_transfer_dest_id = arg; };
        virtual ~MembersRemoveArg(){};

    public:
            /**
                If provided, files from the deleted member account will be
                transferred to this user.
            */
        const UserSelectorArg& transferDestId()const{return m_transfer_dest_id;};
        MembersRemoveArg& setTransferdestid(const UserSelectorArg& arg){m_transfer_dest_id=arg;return *this;};

            /**
                If provided, errors during the transfer process will be sent via
                email to this user. If the transfer_dest_id argument was
                provided, then this argument must be provided as well.
            */
        const UserSelectorArg& transferAdminId()const{return m_transfer_admin_id;};
        MembersRemoveArg& setTransferadminid(const UserSelectorArg& arg){m_transfer_admin_id=arg;return *this;};

            /**
                Downgrade the member to a Basic account. The user will retain
                the email address associated with their Dropbox  account and
                data in their account that is not restricted to team members.
            */
        bool keepAccount()const{return m_keep_account;};
        MembersRemoveArg& setKeepaccount(const bool& arg){m_keep_account=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersRemoveArg>  create(const QByteArray& data);
            static std::unique_ptr<MembersRemoveArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                If provided, files from the deleted member account will be
                transferred to this user.
            */
        UserSelectorArg m_transfer_dest_id;

            /**
                If provided, errors during the transfer process will be sent via
                email to this user. If the transfer_dest_id argument was
                provided, then this argument must be provided as well.
            */
        UserSelectorArg m_transfer_admin_id;

            /**
                Downgrade the member to a Basic account. The user will retain
                the email address associated with their Dropbox  account and
                data in their account that is not restricted to team members.
            */
        bool m_keep_account;

    };//MembersRemoveArg

}//team
}//dropboxQt
