/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamRevokeDeviceSessionError.h"

namespace dropboxQt{
namespace team{
    class RevokeDeviceSessionStatus{
        /**
            field: success: Result of the revoking request
            field: error_type: The error cause in case of a failure
        */

    public:
        RevokeDeviceSessionStatus(){};

        RevokeDeviceSessionStatus(const bool& arg){ m_success = arg; };
        virtual ~RevokeDeviceSessionStatus(){};

    public:
            /**
                Result of the revoking request
            */
        bool success()const{return m_success;};
        RevokeDeviceSessionStatus& setSuccess(const bool& arg){m_success=arg;return *this;};

            /**
                The error cause in case of a failure
            */
        const RevokeDeviceSessionError& errorType()const{return m_error_type;};
        RevokeDeviceSessionStatus& setErrortype(const RevokeDeviceSessionError& arg){m_error_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeDeviceSessionStatus>  create(const QByteArray& data);
            static std::unique_ptr<RevokeDeviceSessionStatus>  create(const QJsonObject& js);
        };



    protected:
            /**
                Result of the revoking request
            */
        bool m_success;

            /**
                The error cause in case of a failure
            */
        RevokeDeviceSessionError m_error_type;

    };//RevokeDeviceSessionStatus

}//team
}//dropboxQt
