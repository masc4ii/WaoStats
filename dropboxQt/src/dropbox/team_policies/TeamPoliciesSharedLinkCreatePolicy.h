/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team_policies{
    class SharedLinkCreatePolicy{
        /**
            Policy governing the visibility of newly created shared links.

            field: default_public: By default, anyone can access newly created
                shared links. No login will be required to access the shared
                links unless overridden.
            field: default_team_only: By default, only members of the same team
                can access newly created shared links. Login will be required to
                access the shared links unless overridden.
            field: team_only: Only members of the same team can access newly
                created shared links. Login will be required to access the
                shared links.
        */
    public:
        enum Tag{

        /*By default, anyone can access newly created shared links. No login will be required to access the shared links unless overridden.*/
        SharedLinkCreatePolicy_DEFAULT_PUBLIC,
        /*By default, only members of the same team can access newly created shared links. Login will be required to access the shared links unless overridden.*/
        SharedLinkCreatePolicy_DEFAULT_TEAM_ONLY,
        /*Only members of the same team can access newly created shared links. Login will be required to access the shared links.*/
        SharedLinkCreatePolicy_TEAM_ONLY,
        /*None*/
        SharedLinkCreatePolicy_OTHER
        };

        SharedLinkCreatePolicy(){}
        SharedLinkCreatePolicy(Tag v):m_tag(v){}
        virtual ~SharedLinkCreatePolicy(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedLinkCreatePolicy>  create(const QByteArray& data);
            static std::unique_ptr<SharedLinkCreatePolicy>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedLinkCreatePolicy

}//team_policies
}//dropboxQt
