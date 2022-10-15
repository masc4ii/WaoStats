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
    class ListTeamAppsError{
        /**
            Error returned by :meth:`linked_apps_list_team_linked_apps`

            field: reset: Indicates that the cursor has been invalidated. Call
                :meth:`linked_apps_list_team_linked_apps` again with an empty
                cursor to obtain a new cursor.
        */
    public:
        enum Tag{

        /*Indicates that the cursor has been invalidated. Call :route:`linked_apps/list_team_linked_apps` again with an empty cursor to obtain a new cursor.*/
        ListTeamAppsError_RESET,
        /*None*/
        ListTeamAppsError_OTHER
        };

        ListTeamAppsError(){}
        ListTeamAppsError(Tag v):m_tag(v){}
        virtual ~ListTeamAppsError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListTeamAppsError>  create(const QByteArray& data);
            static std::unique_ptr<ListTeamAppsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListTeamAppsError

}//team
}//dropboxQt
