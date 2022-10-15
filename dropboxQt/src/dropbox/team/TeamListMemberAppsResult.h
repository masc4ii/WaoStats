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
    class ListMemberAppsResult{
        /**
            field: linked_api_apps: List of third party applications linked by
                this team member
        */

    public:
        ListMemberAppsResult(){};

        ListMemberAppsResult(const std::list <ApiApp>& arg){ m_linked_api_apps = arg; };
        virtual ~ListMemberAppsResult(){};

    public:
            /**
                List of third party applications linked by this team member
            */
        const std::list <ApiApp>& linkedApiApps()const{return m_linked_api_apps;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListMemberAppsResult>  create(const QByteArray& data);
            static std::unique_ptr<ListMemberAppsResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of third party applications linked by this team member
            */
        std::list <ApiApp> m_linked_api_apps;

    };//ListMemberAppsResult

}//team
}//dropboxQt
