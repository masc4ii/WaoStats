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
    class ListMemberDevicesResult{
        /**
            field: active_web_sessions: List of web sessions made by this team
                member
            field: desktop_client_sessions: List of desktop clients used by this
                team member
            field: mobile_client_sessions: List of mobile client used by this
                team member
        */

    public:
        ListMemberDevicesResult(){};

        ListMemberDevicesResult(const std::list <ActiveWebSession>& arg){ m_active_web_sessions = arg; };
        virtual ~ListMemberDevicesResult(){};

    public:
            /**
                List of web sessions made by this team member
            */
        const std::list <ActiveWebSession>& activeWebSessions()const{return m_active_web_sessions;};

            /**
                List of desktop clients used by this team member
            */
        const std::list <DesktopClientSession>& desktopClientSessions()const{return m_desktop_client_sessions;};

            /**
                List of mobile client used by this team member
            */
        const std::list <MobileClientSession>& mobileClientSessions()const{return m_mobile_client_sessions;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListMemberDevicesResult>  create(const QByteArray& data);
            static std::unique_ptr<ListMemberDevicesResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of web sessions made by this team member
            */
        std::list <ActiveWebSession> m_active_web_sessions;

            /**
                List of desktop clients used by this team member
            */
        std::list <DesktopClientSession> m_desktop_client_sessions;

            /**
                List of mobile client used by this team member
            */
        std::list <MobileClientSession> m_mobile_client_sessions;

    };//ListMemberDevicesResult

}//team
}//dropboxQt
