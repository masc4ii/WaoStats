/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamDeviceSession.h"

namespace dropboxQt{
namespace team{
    class ActiveWebSession : public DeviceSession{
        /**
            Information on active web sessions

            field: user_agent: Information on the hosting device
            field: os: Information on the hosting operating system
            field: browser: Information on the browser used for this web session
        */

    public:
        ActiveWebSession(){};

        ActiveWebSession(const QString& arg){ m_user_agent = arg; };
        virtual ~ActiveWebSession(){};

    public:
            /**
                Information on the hosting device
            */
        QString userAgent()const{return m_user_agent;};
        ActiveWebSession& setUseragent(const QString& arg){m_user_agent=arg;return *this;};

            /**
                Information on the hosting operating system
            */
        QString os()const{return m_os;};
        ActiveWebSession& setOs(const QString& arg){m_os=arg;return *this;};

            /**
                Information on the browser used for this web session
            */
        QString browser()const{return m_browser;};
        ActiveWebSession& setBrowser(const QString& arg){m_browser=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ActiveWebSession>  create(const QByteArray& data);
            static std::unique_ptr<ActiveWebSession>  create(const QJsonObject& js);
        };



    protected:
            /**
                Information on the hosting device
            */
        QString m_user_agent;

            /**
                Information on the hosting operating system
            */
        QString m_os;

            /**
                Information on the browser used for this web session
            */
        QString m_browser;

    };//ActiveWebSession

}//team
}//dropboxQt
