/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamRevokeLinkedAppError.h"

namespace dropboxQt{
namespace team{
    class RevokeLinkedAppStatus{
        /**
            field: success: Result of the revoking request
            field: error_type: The error cause in case of a failure
        */

    public:
        RevokeLinkedAppStatus(){};

        RevokeLinkedAppStatus(const bool& arg){ m_success = arg; };
        virtual ~RevokeLinkedAppStatus(){};

    public:
            /**
                Result of the revoking request
            */
        bool success()const{return m_success;};
        RevokeLinkedAppStatus& setSuccess(const bool& arg){m_success=arg;return *this;};

            /**
                The error cause in case of a failure
            */
        const RevokeLinkedAppError& errorType()const{return m_error_type;};
        RevokeLinkedAppStatus& setErrortype(const RevokeLinkedAppError& arg){m_error_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeLinkedAppStatus>  create(const QByteArray& data);
            static std::unique_ptr<RevokeLinkedAppStatus>  create(const QJsonObject& js);
        };



    protected:
            /**
                Result of the revoking request
            */
        bool m_success;

            /**
                The error cause in case of a failure
            */
        RevokeLinkedAppError m_error_type;

    };//RevokeLinkedAppStatus

}//team
}//dropboxQt
