/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "auth"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/auth/AuthRateLimitReason.h"

namespace dropboxQt{
namespace auth{
    class RateLimitError{
        /**
            Error occurred because the app is being rate limited.

            field: reason: The reason why the app is being rate limited.
            field: retry_after: The number of seconds that the app should wait
                before making another request.
        */

    public:
        RateLimitError():
        m_retry_after(1)
        {};

        RateLimitError(const RateLimitReason& arg):
        m_retry_after(1)
        { m_reason = arg; };
        virtual ~RateLimitError(){};

    public:
            /**
                The reason why the app is being rate limited.
            */
        const RateLimitReason& reason()const{return m_reason;};
        RateLimitError& setReason(const RateLimitReason& arg){m_reason=arg;return *this;};

            /**
                The number of seconds that the app should wait before making
                another request.
            */
        int retryAfter()const{return m_retry_after;};
        RateLimitError& setRetryafter(const int& arg){m_retry_after=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RateLimitError>  create(const QByteArray& data);
            static std::unique_ptr<RateLimitError>  create(const QJsonObject& js);
        };



    protected:
            /**
                The reason why the app is being rate limited.
            */
        RateLimitReason m_reason;

            /**
                The number of seconds that the app should wait before making
                another request.
            */
        int m_retry_after = {0};

    };//RateLimitError

}//auth
}//dropboxQt
