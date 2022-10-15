/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupMemberInfo.h"

namespace dropboxQt{
namespace team{
    class GroupsMembersListResult{
        /**
            field: cursor: Pass the cursor into
                :meth:`groups_members_list_continue` to obtain additional group
                members.
            field: has_more: Is true if there are additional group members that
                have not been returned yet. An additional call to
                :meth:`groups_members_list_continue` can retrieve them.
        */

    public:
        GroupsMembersListResult(){};

        GroupsMembersListResult(const std::list <GroupMemberInfo>& arg){ m_members = arg; };
        virtual ~GroupsMembersListResult(){};

    public:
        const std::list <GroupMemberInfo>& members()const{return m_members;};

            /**
                Pass the cursor into :meth:`groups_members_list_continue` to
                obtain additional group members.
            */
        QString cursor()const{return m_cursor;};

            /**
                Is true if there are additional group members that have not been
                returned yet. An additional call to
                :meth:`groups_members_list_continue` can retrieve them.
            */
        bool hasMore()const{return m_has_more;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsMembersListResult>  create(const QByteArray& data);
            static std::unique_ptr<GroupsMembersListResult>  create(const QJsonObject& js);
        };



    protected:
        std::list <GroupMemberInfo> m_members;

            /**
                Pass the cursor into :meth:`groups_members_list_continue` to
                obtain additional group members.
            */
        QString m_cursor;

            /**
                Is true if there are additional group members that have not been
                returned yet. An additional call to
                :meth:`groups_members_list_continue` can retrieve them.
            */
        bool m_has_more;

    };//GroupsMembersListResult

}//team
}//dropboxQt
