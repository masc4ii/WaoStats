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
    class ListMemberDevicesError{
        /**
            field: member_not_found: Member not found.
        */
    public:
        enum Tag{

        /*Member not found.*/
        ListMemberDevicesError_MEMBER_NOT_FOUND,
        /*None*/
        ListMemberDevicesError_OTHER
        };

        ListMemberDevicesError(){}
        ListMemberDevicesError(Tag v):m_tag(v){}
        virtual ~ListMemberDevicesError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListMemberDevicesError>  create(const QByteArray& data);
            static std::unique_ptr<ListMemberDevicesError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListMemberDevicesError

}//team
}//dropboxQt
