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
    class UserSelectorError{
        /**
            Error that can be returned whenever a struct derived from
            :class:`UserSelectorArg` is used.

            field: user_not_found: No matching user found. The provided
                team_member_id, email, or external_id does not exist on this
                team.
        */
    public:
        enum Tag{

        /*No matching user found. The provided team_member_id, email, or external_id does not exist on this team.*/
        UserSelectorError_USER_NOT_FOUND
        };

        UserSelectorError(){}
        UserSelectorError(Tag v):m_tag(v){}
        virtual ~UserSelectorError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UserSelectorError>  create(const QByteArray& data);
            static std::unique_ptr<UserSelectorError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//UserSelectorError

}//team
}//dropboxQt
