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
    class GetAccountError{
        /**
            field: no_account: The specified ``GetAccountArg.account_id`` does
                not exist.
        */
    public:
        enum Tag{

        /*The specified :field:`GetAccountArg.account_id` does not exist.*/
        GetAccountError_NO_ACCOUNT,
        /*None*/
        GetAccountError_OTHER
        };

        GetAccountError(){}
        GetAccountError(Tag v):m_tag(v){}
        virtual ~GetAccountError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetAccountError>  create(const QByteArray& data);
            static std::unique_ptr<GetAccountError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GetAccountError

}//users
}//dropboxQt
