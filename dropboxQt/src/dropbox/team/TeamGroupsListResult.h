/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team_common/TeamCommonGroupSummary.h"

namespace dropboxQt{
namespace team{
    class GroupsListResult{
        /**
            field: cursor: Pass the cursor into :meth:`groups_list_continue` to
                obtain the additional groups.
            field: has_more: Is true if there are additional groups that have
                not been returned yet. An additional call to
                :meth:`groups_list_continue` can retrieve them.
        */

    public:
        GroupsListResult(){};

        GroupsListResult(const std::list <team_common::GroupSummary>& arg){ m_groups = arg; };
        virtual ~GroupsListResult(){};

    public:
        const std::list <team_common::GroupSummary>& groups()const{return m_groups;};

            /**
                Pass the cursor into :meth:`groups_list_continue` to obtain the
                additional groups.
            */
        QString cursor()const{return m_cursor;};

            /**
                Is true if there are additional groups that have not been
                returned yet. An additional call to :meth:`groups_list_continue`
                can retrieve them.
            */
        bool hasMore()const{return m_has_more;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsListResult>  create(const QByteArray& data);
            static std::unique_ptr<GroupsListResult>  create(const QJsonObject& js);
        };



    protected:
        std::list <team_common::GroupSummary> m_groups;

            /**
                Pass the cursor into :meth:`groups_list_continue` to obtain the
                additional groups.
            */
        QString m_cursor;

            /**
                Is true if there are additional groups that have not been
                returned yet. An additional call to :meth:`groups_list_continue`
                can retrieve them.
            */
        bool m_has_more;

    };//GroupsListResult

}//team
}//dropboxQt
