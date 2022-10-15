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
    class SharedLinkAccessFailureReason{
        /**
            field: login_required: User is not logged in.
            field: email_verify_required: User's email is not verified.
            field: password_required: The link is password protected.
            field: team_only: Access is allowed for team members only.
            field: owner_only: Access is allowed for the shared link's owner
                only.
        */
    public:
        enum Tag{

        /*User is not logged in.*/
        SharedLinkAccessFailureReason_LOGIN_REQUIRED,
        /*User's email is not verified.*/
        SharedLinkAccessFailureReason_EMAIL_VERIFY_REQUIRED,
        /*The link is password protected.*/
        SharedLinkAccessFailureReason_PASSWORD_REQUIRED,
        /*Access is allowed for team members only.*/
        SharedLinkAccessFailureReason_TEAM_ONLY,
        /*Access is allowed for the shared link's owner only.*/
        SharedLinkAccessFailureReason_OWNER_ONLY,
        /*None*/
        SharedLinkAccessFailureReason_OTHER
        };

        SharedLinkAccessFailureReason(){}
        SharedLinkAccessFailureReason(Tag v):m_tag(v){}
        virtual ~SharedLinkAccessFailureReason(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedLinkAccessFailureReason>  create(const QByteArray& data);
            static std::unique_ptr<SharedLinkAccessFailureReason>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedLinkAccessFailureReason

}//sharing
}//dropboxQt
