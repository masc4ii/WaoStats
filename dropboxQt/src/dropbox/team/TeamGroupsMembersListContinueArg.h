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
    class GroupsMembersListContinueArg{
        /**
            field: cursor: Indicates from what point to get the next set of
                groups.
        */

    public:
        GroupsMembersListContinueArg(){};

        GroupsMembersListContinueArg(const QString& arg){ m_cursor = arg; };
        virtual ~GroupsMembersListContinueArg(){};

    public:
            /**
                Indicates from what point to get the next set of groups.
            */
        QString cursor()const{return m_cursor;};
        GroupsMembersListContinueArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsMembersListContinueArg>  create(const QByteArray& data);
            static std::unique_ptr<GroupsMembersListContinueArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Indicates from what point to get the next set of groups.
            */
        QString m_cursor;

    };//GroupsMembersListContinueArg

}//team
}//dropboxQt
