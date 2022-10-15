/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedLinkError.h"

namespace dropboxQt{
namespace sharing{
    class RevokeSharedLinkError{
        /**
            field: shared_link_malformed: Shared link is malformed.
        */
    public:
        enum Tag{

        /*The shared link wasn't found*/
        SharedLinkError_SHARED_LINK_NOT_FOUND,
        /*The caller is not allowed to access this shared link*/
        SharedLinkError_SHARED_LINK_ACCESS_DENIED,
        /*None*/
        SharedLinkError_OTHER,
        /*Shared link is malformed.*/
        RevokeSharedLinkError_SHARED_LINK_MALFORMED
        };

        RevokeSharedLinkError(){}
        RevokeSharedLinkError(Tag v):m_tag(v){}
        virtual ~RevokeSharedLinkError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RevokeSharedLinkError>  create(const QByteArray& data);
            static std::unique_ptr<RevokeSharedLinkError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//RevokeSharedLinkError

}//sharing
}//dropboxQt
