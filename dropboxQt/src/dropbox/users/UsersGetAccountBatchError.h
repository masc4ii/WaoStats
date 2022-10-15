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
    class GetAccountBatchError{
        /**
            field: no_account: The value is an account ID specified in
                ``GetAccountBatchArg.account_ids`` that does not exist.
        */
    public:
        enum Tag{

        /*The value is an account ID specified in :field:`GetAccountBatchArg.account_ids` that does not exist.*/
        GetAccountBatchError_NO_ACCOUNT,
        /*None*/
        GetAccountBatchError_OTHER
        };

        GetAccountBatchError(){}
        GetAccountBatchError(Tag v):m_tag(v){}
        virtual ~GetAccountBatchError(){}

        Tag tag()const{return m_tag;}
        ///The value is an account ID specified in :field:`GetAccountBatchArg.account_ids` that does not exist.
        QString getNoAccount()const{API_CHECK_STATE((GetAccountBatchError_NO_ACCOUNT == m_tag), "expected tag: GetAccountBatchError_NO_ACCOUNT", m_tag);return m_no_account;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetAccountBatchError>  create(const QByteArray& data);
            static std::unique_ptr<GetAccountBatchError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_no_account;
    };//GetAccountBatchError

}//users
}//dropboxQt
