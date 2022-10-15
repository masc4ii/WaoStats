/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamTeamMemberInfo.h"

namespace dropboxQt{
namespace team{
    class MembersListResult{
        /**
            field: members: List of team members.
            field: cursor: Pass the cursor into :meth:`members_list_continue` to
                obtain the additional members.
            field: has_more: Is true if there are additional team members that
                have not been returned yet. An additional call to
                :meth:`members_list_continue` can retrieve them.
        */

    public:
        MembersListResult(){};

        MembersListResult(const std::list <TeamMemberInfo>& arg){ m_members = arg; };
        virtual ~MembersListResult(){};

    public:
            /**
                List of team members.
            */
        const std::list <TeamMemberInfo>& members()const{return m_members;};

            /**
                Pass the cursor into :meth:`members_list_continue` to obtain the
                additional members.
            */
        QString cursor()const{return m_cursor;};

            /**
                Is true if there are additional team members that have not been
                returned yet. An additional call to
                :meth:`members_list_continue` can retrieve them.
            */
        bool hasMore()const{return m_has_more;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersListResult>  create(const QByteArray& data);
            static std::unique_ptr<MembersListResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of team members.
            */
        std::list <TeamMemberInfo> m_members;

            /**
                Pass the cursor into :meth:`members_list_continue` to obtain the
                additional members.
            */
        QString m_cursor;

            /**
                Is true if there are additional team members that have not been
                returned yet. An additional call to
                :meth:`members_list_continue` can retrieve them.
            */
        bool m_has_more;

    };//MembersListResult

}//team
}//dropboxQt
