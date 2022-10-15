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

namespace dropboxQt{
namespace sharing{
    class ListFolderMembersCursorArg{
        /**
            field: actions: This is a list indicating whether each returned
                member will include a boolean value ``MemberPermission.allow``
                that describes whether the current user can perform the
                MemberAction on the member.
            field: limit: The maximum number of results that include members,
                groups and invitees to return per request.
        */

    public:
        ListFolderMembersCursorArg():
        m_limit(1000)
        {};

        ListFolderMembersCursorArg(const std::list <MemberAction>& arg):
        m_limit(1000)
        { m_actions = arg; };
        virtual ~ListFolderMembersCursorArg(){};

    public:
            /**
                This is a list indicating whether each returned member will
                include a boolean value ``MemberPermission.allow`` that
                describes whether the current user can perform the MemberAction
                on the member.
            */
        const std::list <MemberAction>& actions()const{return m_actions;};
        ListFolderMembersCursorArg& setActions(const std::list <MemberAction>& arg){m_actions=arg;return *this;};

            /**
                The maximum number of results that include members, groups and
                invitees to return per request.
            */
        int limit()const{return m_limit;};
        ListFolderMembersCursorArg& setLimit(const int& arg){m_limit=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderMembersCursorArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderMembersCursorArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                This is a list indicating whether each returned member will
                include a boolean value ``MemberPermission.allow`` that
                describes whether the current user can perform the MemberAction
                on the member.
            */
        std::list <MemberAction> m_actions;

            /**
                The maximum number of results that include members, groups and
                invitees to return per request.
            */
        int m_limit = {0};

    };//ListFolderMembersCursorArg

}//sharing
}//dropboxQt
