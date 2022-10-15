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

namespace dropboxQt{
namespace sharing{
    class RemoveFileMemberArg{
        /**
            Arguments for :meth:`remove_file_member_2`.

            field: file: File from which to remove members.
            field: member: Member to remove from this file. Note that even if an
                email is specified, it may result in the removal of a user (not
                an invitee) if the user's main account corresponds to that email
                address.
        */

    public:
        RemoveFileMemberArg(){};

        RemoveFileMemberArg(const QString& arg){ m_file = arg; };
        virtual ~RemoveFileMemberArg(){};

    public:
            /**
                File from which to remove members.
            */
        QString file()const{return m_file;};
        RemoveFileMemberArg& setFile(const QString& arg){m_file=arg;return *this;};

            /**
                Member to remove from this file. Note that even if an email is
                specified, it may result in the removal of a user (not an
                invitee) if the user's main account corresponds to that email
                address.
            */
        const MemberSelector& member()const{return m_member;};
        RemoveFileMemberArg& setMember(const MemberSelector& arg){m_member=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemoveFileMemberArg>  create(const QByteArray& data);
            static std::unique_ptr<RemoveFileMemberArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                File from which to remove members.
            */
        QString m_file;

            /**
                Member to remove from this file. Note that even if an email is
                specified, it may result in the removal of a user (not an
                invitee) if the user's main account corresponds to that email
                address.
            */
        MemberSelector m_member;

    };//RemoveFileMemberArg

}//sharing
}//dropboxQt
