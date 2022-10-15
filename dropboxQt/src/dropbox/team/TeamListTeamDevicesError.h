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
    class ListTeamDevicesError{
        /**
            field: reset: Indicates that the cursor has been invalidated. Call
                :meth:`devices_list_team_devices` again with an empty cursor to
                obtain a new cursor.
        */
    public:
        enum Tag{

        /*Indicates that the cursor has been invalidated. Call :route:`devices/list_team_devices` again with an empty cursor to obtain a new cursor.*/
        ListTeamDevicesError_RESET,
        /*None*/
        ListTeamDevicesError_OTHER
        };

        ListTeamDevicesError(){}
        ListTeamDevicesError(Tag v):m_tag(v){}
        virtual ~ListTeamDevicesError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListTeamDevicesError>  create(const QByteArray& data);
            static std::unique_ptr<ListTeamDevicesError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListTeamDevicesError

}//team
}//dropboxQt
