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
    class MembersListContinueError{
        /**
            field: invalid_cursor: The cursor is invalid.
        */
    public:
        enum Tag{

        /*The cursor is invalid.*/
        MembersListContinueError_INVALID_CURSOR,
        /*None*/
        MembersListContinueError_OTHER
        };

        MembersListContinueError(){}
        MembersListContinueError(Tag v):m_tag(v){}
        virtual ~MembersListContinueError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersListContinueError>  create(const QByteArray& data);
            static std::unique_ptr<MembersListContinueError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MembersListContinueError

}//team
}//dropboxQt
