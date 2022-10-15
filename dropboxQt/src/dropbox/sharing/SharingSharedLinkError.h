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
    class SharedLinkError{
        /**
            field: shared_link_not_found: The shared link wasn't found
            field: shared_link_access_denied: The caller is not allowed to
                access this shared link
        */
    public:
        enum Tag{

        /*The shared link wasn't found*/
        SharedLinkError_SHARED_LINK_NOT_FOUND,
        /*The caller is not allowed to access this shared link*/
        SharedLinkError_SHARED_LINK_ACCESS_DENIED,
        /*None*/
        SharedLinkError_OTHER
        };

        SharedLinkError(){}
        SharedLinkError(Tag v):m_tag(v){}
        virtual ~SharedLinkError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedLinkError>  create(const QByteArray& data);
            static std::unique_ptr<SharedLinkError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedLinkError

}//sharing
}//dropboxQt
