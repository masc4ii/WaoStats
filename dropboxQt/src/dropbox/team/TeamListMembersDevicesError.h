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
    class ListMembersDevicesError{
        /**
            field: reset: Indicates that the cursor has been invalidated. Call
                :meth:`devices_list_members_devices` again with an empty cursor
                to obtain a new cursor.
        */
    public:
        enum Tag{

        /*Indicates that the cursor has been invalidated. Call :route:`devices/list_members_devices` again with an empty cursor to obtain a new cursor.*/
        ListMembersDevicesError_RESET,
        /*None*/
        ListMembersDevicesError_OTHER
        };

        ListMembersDevicesError(){}
        ListMembersDevicesError(Tag v):m_tag(v){}
        virtual ~ListMembersDevicesError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListMembersDevicesError>  create(const QByteArray& data);
            static std::unique_ptr<ListMembersDevicesError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListMembersDevicesError

}//team
}//dropboxQt
