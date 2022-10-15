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
    class GetAccountBatchArg{
        /**
            field: account_ids: List of user account identifiers.  Should not
                contain any duplicate account IDs.
        */

    public:
        GetAccountBatchArg(){};

        GetAccountBatchArg(const std::list <QString>& arg){ m_account_ids = arg; };
        virtual ~GetAccountBatchArg(){};

    public:
            /**
                List of user account identifiers.  Should not contain any
                duplicate account IDs.
            */
        const std::list <QString>& accountIds()const{return m_account_ids;};
        GetAccountBatchArg& setAccountids(const std::list <QString>& arg){m_account_ids=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetAccountBatchArg>  create(const QByteArray& data);
            static std::unique_ptr<GetAccountBatchArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of user account identifiers.  Should not contain any
                duplicate account IDs.
            */
        std::list <QString> m_account_ids;

    };//GetAccountBatchArg

}//users
}//dropboxQt
