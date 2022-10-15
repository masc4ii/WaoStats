/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamApiApp.h"

namespace dropboxQt{
namespace team{
    class MemberLinkedApps{
        /**
            Information on linked applications of a team member.

            field: team_member_id: The member unique Id
            field: linked_api_apps: List of third party applications linked by
                this team member
        */

    public:
        MemberLinkedApps(){};

        MemberLinkedApps(const QString& arg){ m_team_member_id = arg; };
        virtual ~MemberLinkedApps(){};

    public:
            /**
                The member unique Id
            */
        QString teamMemberId()const{return m_team_member_id;};
        MemberLinkedApps& setTeammemberid(const QString& arg){m_team_member_id=arg;return *this;};

            /**
                List of third party applications linked by this team member
            */
        const std::list <ApiApp>& linkedApiApps()const{return m_linked_api_apps;};
        MemberLinkedApps& setLinkedapiapps(const std::list <ApiApp>& arg){m_linked_api_apps=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberLinkedApps>  create(const QByteArray& data);
            static std::unique_ptr<MemberLinkedApps>  create(const QJsonObject& js);
        };



    protected:
            /**
                The member unique Id
            */
        QString m_team_member_id;

            /**
                List of third party applications linked by this team member
            */
        std::list <ApiApp> m_linked_api_apps;

    };//MemberLinkedApps

}//team
}//dropboxQt
