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
    class RequestedVisibility{
        /**
            The access permission that can be requested by the caller for the
            shared link. Note that the final resolved visibility of the shared
            link takes into account other aspects, such as team and shared
            folder settings. Check the :class:`ResolvedVisibility` for more info
            on the possible resolved visibility values of shared links.

            field: public: Anyone who has received the link can access it. No
                login required.
            field: team_only: Only members of the same team can access the link.
                Login is required.
            field: password: A link-specific password is required to access the
                link. Login is not required.
        */
    public:
        enum Tag{

        /*Anyone who has received the link can access it. No login required.*/
        RequestedVisibility_PUBLIC,
        /*Only members of the same team can access the link. Login is required.*/
        RequestedVisibility_TEAM_ONLY,
        /*A link-specific password is required to access the link. Login is not required.*/
        RequestedVisibility_PASSWORD
        };

        RequestedVisibility(){}
        RequestedVisibility(Tag v):m_tag(v){}
        virtual ~RequestedVisibility(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RequestedVisibility>  create(const QByteArray& data);
            static std::unique_ptr<RequestedVisibility>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//RequestedVisibility

}//sharing
}//dropboxQt
