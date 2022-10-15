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
    class ListMemberAppsError{
        /**
            Error returned by :meth:`linked_apps_list_member_linked_apps`.

            field: member_not_found: Member not found.
        */
    public:
        enum Tag{

        /*Member not found.*/
        ListMemberAppsError_MEMBER_NOT_FOUND,
        /*None*/
        ListMemberAppsError_OTHER
        };

        ListMemberAppsError(){}
        ListMemberAppsError(Tag v):m_tag(v){}
        virtual ~ListMemberAppsError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListMemberAppsError>  create(const QByteArray& data);
            static std::unique_ptr<ListMemberAppsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//ListMemberAppsError

}//team
}//dropboxQt
