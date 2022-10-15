/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMemberLinkedApps.h"

namespace dropboxQt{
namespace team{
    class ListTeamAppsResult{
        /**
            Information returned by :meth:`linked_apps_list_team_linked_apps`.

            field: apps: The linked applications of each member of the team
            field: has_more: If true, then there are more apps available. Pass
                the cursor to :meth:`linked_apps_list_team_linked_apps` to
                retrieve the rest.
            field: cursor: Pass the cursor into
                :meth:`linked_apps_list_team_linked_apps` to receive the next
                sub list of team's applications.
        */

    public:
        ListTeamAppsResult(){};

        ListTeamAppsResult(const std::list <MemberLinkedApps>& arg){ m_apps = arg; };
        virtual ~ListTeamAppsResult(){};

    public:
            /**
                The linked applications of each member of the team
            */
        const std::list <MemberLinkedApps>& apps()const{return m_apps;};

            /**
                If true, then there are more apps available. Pass the cursor to
                :meth:`linked_apps_list_team_linked_apps` to retrieve the rest.
            */
        bool hasMore()const{return m_has_more;};

            /**
                Pass the cursor into :meth:`linked_apps_list_team_linked_apps`
                to receive the next sub list of team's applications.
            */
        QString cursor()const{return m_cursor;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListTeamAppsResult>  create(const QByteArray& data);
            static std::unique_ptr<ListTeamAppsResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                The linked applications of each member of the team
            */
        std::list <MemberLinkedApps> m_apps;

            /**
                If true, then there are more apps available. Pass the cursor to
                :meth:`linked_apps_list_team_linked_apps` to retrieve the rest.
            */
        bool m_has_more;

            /**
                Pass the cursor into :meth:`linked_apps_list_team_linked_apps`
                to receive the next sub list of team's applications.
            */
        QString m_cursor;

    };//ListTeamAppsResult

}//team
}//dropboxQt
