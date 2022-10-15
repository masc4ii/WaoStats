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
    class AccountType{
        /**
            What type of account this user has.

            field: basic: The basic account type.
            field: pro: The Dropbox Pro account type.
            field: business: The Dropbox Business account type.
        */
    public:
        enum Tag{

        /*The basic account type.*/
        AccountType_BASIC,
        /*The Dropbox Pro account type.*/
        AccountType_PRO,
        /*The Dropbox Business account type.*/
        AccountType_BUSINESS
        };

        AccountType(){}
        AccountType(Tag v):m_tag(v){}
        virtual ~AccountType(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AccountType>  create(const QByteArray& data);
            static std::unique_ptr<AccountType>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//AccountType

}//users
}//dropboxQt
