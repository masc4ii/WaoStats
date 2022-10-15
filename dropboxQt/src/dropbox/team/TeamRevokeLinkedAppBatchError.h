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
    class RevokeLinkedAppBatchError{
        /**
            Error returned by :meth:`linked_apps_revoke_linked_app_batch`.
        */
    public:
        enum Tag{

        /*None*/
        RevokeLinkedAppBatchError_OTHER
        };

        RevokeLinkedAppBatchError(){}
        RevokeLinkedAppBatchError(Tag v):m_tag(v){}
        virtual ~RevokeLinkedAppBatchError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeLinkedAppBatchError>  create(const QByteArray& data);
            static std::unique_ptr<RevokeLinkedAppBatchError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//RevokeLinkedAppBatchError

}//team
}//dropboxQt
