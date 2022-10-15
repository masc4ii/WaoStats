/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingRequestedVisibility.h"

namespace dropboxQt{
namespace sharing{
    class ResolvedVisibility{
        /**
            The actual access permissions values of shared links after taking
            into account user preferences and the team and shared folder
            settings. Check the :class:`RequestedVisibility` for more info on
            the possible visibility values that can be set by the shared link's
            owner.

            field: team_and_password: Only members of the same team who have the
                link-specific password can access the link. Login is required.
            field: shared_folder_only: Only members of the shared folder
                containing the linked file can access the link. Login is
                required.
        */
    public:
        enum Tag{

        /*Anyone who has received the link can access it. No login required.*/
        RequestedVisibility_PUBLIC,
        /*Only members of the same team can access the link. Login is required.*/
        RequestedVisibility_TEAM_ONLY,
        /*A link-specific password is required to access the link. Login is not required.*/
        RequestedVisibility_PASSWORD,
        /*Only members of the same team who have the link-specific password can access the link. Login is required.*/
        ResolvedVisibility_TEAM_AND_PASSWORD,
        /*Only members of the shared folder containing the linked file can access the link. Login is required.*/
        ResolvedVisibility_SHARED_FOLDER_ONLY,
        /*None*/
        ResolvedVisibility_OTHER
        };

        ResolvedVisibility(){}
        ResolvedVisibility(Tag v):m_tag(v){}
        virtual ~ResolvedVisibility(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ResolvedVisibility>  create(const QByteArray& data);
            static std::unique_ptr<ResolvedVisibility>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ResolvedVisibility

}//sharing
}//dropboxQt
