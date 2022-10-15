/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace users{
    class GetAccountArg{
        /**
            field: account_id: A user's account identifier.
        */

    public:
        GetAccountArg(){};

        GetAccountArg(const QString& arg){ m_account_id = arg; };
        virtual ~GetAccountArg(){};

    public:
            /**
                A user's account identifier.
            */
        QString accountId()const{return m_account_id;};
        GetAccountArg& setAccountid(const QString& arg){m_account_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetAccountArg>  create(const QByteArray& data);
            static std::unique_ptr<GetAccountArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                A user's account identifier.
            */
        QString m_account_id;

    };//GetAccountArg

}//users
}//dropboxQt
