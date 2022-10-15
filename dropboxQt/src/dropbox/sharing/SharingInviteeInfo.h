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
    class InviteeInfo{
        /**
            Information about the recipient of a shared content invitation.

            field: email: E-mail address of invited user.
        */
    public:
        enum Tag{

        /*E-mail address of invited user.*/
        InviteeInfo_EMAIL,
        /*None*/
        InviteeInfo_OTHER
        };

        InviteeInfo(){}
        InviteeInfo(Tag v):m_tag(v){}
        virtual ~InviteeInfo(){}

        Tag tag()const{return m_tag;}
        ///E-mail address of invited user.
        QString getEmail()const{API_CHECK_STATE((InviteeInfo_EMAIL == m_tag), "expected tag: InviteeInfo_EMAIL", m_tag);return m_email;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<InviteeInfo>  create(const QByteArray& data);
            static std::unique_ptr<InviteeInfo>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_email;
    };//InviteeInfo

}//sharing
}//dropboxQt
