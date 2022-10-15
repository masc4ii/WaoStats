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
    class SharedLinkPolicy{
        /**
            Policy governing who can view shared links.

            field: anyone: Links can be shared with anyone.
            field: members: Links can only be shared among members of the shared
                folder.
        */
    public:
        enum Tag{

        /*Links can be shared with anyone.*/
        SharedLinkPolicy_ANYONE,
        /*Links can only be shared among members of the shared folder.*/
        SharedLinkPolicy_MEMBERS,
        /*None*/
        SharedLinkPolicy_OTHER
        };

        SharedLinkPolicy(){}
        SharedLinkPolicy(Tag v):m_tag(v){}
        virtual ~SharedLinkPolicy(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedLinkPolicy>  create(const QByteArray& data);
            static std::unique_ptr<SharedLinkPolicy>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedLinkPolicy

}//sharing
}//dropboxQt
