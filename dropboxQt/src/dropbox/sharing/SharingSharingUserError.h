/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class SharingUserError{
        /**
            User account had a problem preventing this action.

            field: email_unverified: The current user must verify the account
                e-mail address before performing this action.
        */
    public:
        enum Tag{

        /*The current user must verify the account e-mail address before performing this action.*/
        SharingUserError_EMAIL_UNVERIFIED,
        /*None*/
        SharingUserError_OTHER
        };

        SharingUserError(){}
        SharingUserError(Tag v):m_tag(v){}
        virtual ~SharingUserError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharingUserError>  create(const QByteArray& data);
            static std::unique_ptr<SharingUserError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharingUserError

}//sharing
}//dropboxQt
