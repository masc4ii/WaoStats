/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamRevokeDeviceSessionArg.h"

namespace dropboxQt{
namespace team{
    class RevokeDeviceSessionBatchArg{

    public:
        RevokeDeviceSessionBatchArg(){};

        RevokeDeviceSessionBatchArg(const std::list <RevokeDeviceSessionArg>& arg){ m_revoke_devices = arg; };
        virtual ~RevokeDeviceSessionBatchArg(){};

    public:
        const std::list <RevokeDeviceSessionArg>& revokeDevices()const{return m_revoke_devices;};
        RevokeDeviceSessionBatchArg& setRevokedevices(const std::list <RevokeDeviceSessionArg>& arg){m_revoke_devices=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeDeviceSessionBatchArg>  create(const QByteArray& data);
            static std::unique_ptr<RevokeDeviceSessionBatchArg>  create(const QJsonObject& js);
        };



    protected:
        std::list <RevokeDeviceSessionArg> m_revoke_devices;

    };//RevokeDeviceSessionBatchArg

}//team
}//dropboxQt
