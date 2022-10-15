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
    class AddFileMemberArgs{
        /**
            Arguments for :meth:`add_file_member`.

            field: file: File to which to add members.
            field: members: Members to add. Note that even an email address is
                given, this may result in a user being directy added to the
                membership if that email is the user's main account email.
            field: custom_message: Message to send to added members in their
                invitation.
            field: quiet: Whether added members should be notified via device
                notifications of their invitation.
            field: access_level: AccessLevel union object, describing what
                access level we want to give new members.
            field: add_message_as_comment: If the custom message should be added
                as a comment on the file.
        */

    public:
        AddFileMemberArgs():
        m_quiet(false)
        ,m_access_level(AccessLevel::AccessLevel_VIEWER)
        ,m_add_message_as_comment(false)
        {};

        AddFileMemberArgs(const QString& arg):
        m_quiet(false)
        ,m_access_level(AccessLevel::AccessLevel_VIEWER)
        ,m_add_message_as_comment(false)
        { m_file = arg; };
        virtual ~AddFileMemberArgs(){};

    public:
            /**
                File to which to add members.
            */
        QString file()const{return m_file;};
        AddFileMemberArgs& setFile(const QString& arg){m_file=arg;return *this;};

            /**
                Members to add. Note that even an email address is given, this
                may result in a user being directy added to the membership if
                that email is the user's main account email.
            */
        const std::list <MemberSelector>& members()const{return m_members;};
        AddFileMemberArgs& setMembers(const std::list <MemberSelector>& arg){m_members=arg;return *this;};

            /**
                Message to send to added members in their invitation.
            */
        QString customMessage()const{return m_custom_message;};
        AddFileMemberArgs& setCustommessage(const QString& arg){m_custom_message=arg;return *this;};

            /**
                Whether added members should be notified via device
                notifications of their invitation.
            */
        bool quiet()const{return m_quiet;};
        AddFileMemberArgs& setQuiet(const bool& arg){m_quiet=arg;return *this;};

            /**
                AccessLevel union object, describing what access level we want
                to give new members.
            */
        const AccessLevel& accessLevel()const{return m_access_level;};
        AddFileMemberArgs& setAccesslevel(const AccessLevel& arg){m_access_level=arg;return *this;};

            /**
                If the custom message should be added as a comment on the file.
            */
        bool addMessageAsComment()const{return m_add_message_as_comment;};
        AddFileMemberArgs& setAddmessageascomment(const bool& arg){m_add_message_as_comment=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AddFileMemberArgs>  create(const QByteArray& data);
            static std::unique_ptr<AddFileMemberArgs>  create(const QJsonObject& js);
        };



    protected:
            /**
                File to which to add members.
            */
        QString m_file;

            /**
                Members to add. Note that even an email address is given, this
                may result in a user being directy added to the membership if
                that email is the user's main account email.
            */
        std::list <MemberSelector> m_members;

            /**
                Message to send to added members in their invitation.
            */
        QString m_custom_message;

            /**
                Whether added members should be notified via device
                notifications of their invitation.
            */
        bool m_quiet;

            /**
                AccessLevel union object, describing what access level we want
                to give new members.
            */
        AccessLevel m_access_level;

            /**
                If the custom message should be added as a comment on the file.
            */
        bool m_add_message_as_comment;

    };//AddFileMemberArgs

}//sharing
}//dropboxQt
