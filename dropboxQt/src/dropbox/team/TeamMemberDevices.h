/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamActiveWebSession.h"
#include "dropbox/team/TeamDesktopClientSession.h"
#include "dropbox/team/TeamMobileClientSession.h"

namespace dropboxQt{
namespace team{
    class MemberDevices{
        /**
            Information on devices of a team's member.

            field: team_member_id: The member unique Id
            field: web_sessions: List of web sessions made by this team member
            field: desktop_clients: List of desktop clients by this team member
            field: mobile_clients: List of mobile clients by this team member
        */

    public:
        MemberDevices(){};

        MemberDevices(const QString& arg){ m_team_member_id = arg; };
        virtual ~MemberDevices(){};

    public:
            /**
                The member unique Id
            */
        QString teamMemberId()const{return m_team_member_id;};
        MemberDevices& setTeammemberid(const QString& arg){m_team_member_id=arg;return *this;};

            /**
                List of web sessions made by this team member
            */
        const std::list <ActiveWebSession>& webSessions()const{return m_web_sessions;};
        MemberDevices& setWebsessions(const std::list <ActiveWebSession>& arg){m_web_sessions=arg;return *this;};

            /**
                List of desktop clients by this team member
            */
        const std::list <DesktopClientSession>& desktopClients()const{return m_desktop_clients;};
        MemberDevices& setDesktopclients(const std::list <DesktopClientSession>& arg){m_desktop_clients=arg;return *this;};

            /**
                List of mobile clients by this team member
            */
        const std::list <MobileClientSession>& mobileClients()const{return m_mobile_clients;};
        MemberDevices& setMobileclients(const std::list <MobileClientSession>& arg){m_mobile_clients=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberDevices>  create(const QByteArray& data);
            static std::unique_ptr<MemberDevices>  create(const QJsonObject& js);
        };



    protected:
            /**
                The member unique Id
            */
        QString m_team_member_id;

            /**
                List of web sessions made by this team member
            */
        std::list <ActiveWebSession> m_web_sessions;

            /**
                List of desktop clients by this team member
            */
        std::list <DesktopClientSession> m_desktop_clients;

            /**
                List of mobile clients by this team member
            */
        std::list <MobileClientSession> m_mobile_clients;

    };//MemberDevices

}//team
}//dropboxQt
