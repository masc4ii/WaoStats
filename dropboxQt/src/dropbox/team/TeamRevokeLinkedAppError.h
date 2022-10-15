/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team{
    class RevokeLinkedAppError{
        /**
            Error returned by :meth:`linked_apps_revoke_linked_app`.

            field: app_not_found: Application not found.
            field: member_not_found: Member not found.
        */
    public:
        enum Tag{

        /*Application not found.*/
        RevokeLinkedAppError_APP_NOT_FOUND,
        /*Member not found.*/
        RevokeLinkedAppError_MEMBER_NOT_FOUND,
        /*None*/
        RevokeLinkedAppError_OTHER
        };

        RevokeLinkedAppError(){}
        RevokeLinkedAppError(Tag v):m_tag(v){}
        virtual ~RevokeLinkedAppError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeLinkedAppError>  create(const QByteArray& data);
            static std::unique_ptr<RevokeLinkedAppError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//RevokeLinkedAppError

}//team
}//dropboxQt
