/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamDeviceSessionArg.h"
#include "dropbox/team/TeamRevokeDesktopClientArg.h"

namespace dropboxQt{
namespace team{
    class RevokeDeviceSessionArg{
        /**
            field: web_session: End an active session
            field: desktop_client: Unlink a linked desktop device
            field: mobile_client: Unlink a linked mobile device
        */
    public:
        enum Tag{

        /*End an active session*/
        RevokeDeviceSessionArg_WEB_SESSION,
        /*Unlink a linked desktop device*/
        RevokeDeviceSessionArg_DESKTOP_CLIENT,
        /*Unlink a linked mobile device*/
        RevokeDeviceSessionArg_MOBILE_CLIENT
        };

        RevokeDeviceSessionArg(){}
        RevokeDeviceSessionArg(Tag v):m_tag(v){}
        virtual ~RevokeDeviceSessionArg(){}

        Tag tag()const{return m_tag;}
        ///End an active session
        const DeviceSessionArg& getWebSession()const{API_CHECK_STATE((RevokeDeviceSessionArg_WEB_SESSION == m_tag), "expected tag: RevokeDeviceSessionArg_WEB_SESSION", m_tag);return m_web_session;};

        ///Unlink a linked desktop device
        const RevokeDesktopClientArg& getDesktopClient()const{API_CHECK_STATE((RevokeDeviceSessionArg_DESKTOP_CLIENT == m_tag), "expected tag: RevokeDeviceSessionArg_DESKTOP_CLIENT", m_tag);return m_desktop_client;};

        ///Unlink a linked mobile device
        const DeviceSessionArg& getMobileClient()const{API_CHECK_STATE((RevokeDeviceSessionArg_MOBILE_CLIENT == m_tag), "expected tag: RevokeDeviceSessionArg_MOBILE_CLIENT", m_tag);return m_mobile_client;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeDeviceSessionArg>  create(const QByteArray& data);
            static std::unique_ptr<RevokeDeviceSessionArg>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        DeviceSessionArg m_web_session;
        RevokeDesktopClientArg m_desktop_client;
        DeviceSessionArg m_mobile_client;
    };//RevokeDeviceSessionArg

}//team
}//dropboxQt
