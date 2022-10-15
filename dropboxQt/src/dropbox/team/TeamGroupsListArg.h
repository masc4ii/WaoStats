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
    class GroupsListArg{
        /**
            field: limit: Number of results to return per call.
        */

    public:
        GroupsListArg():
        m_limit(1000)
        {};

        GroupsListArg(const int& arg):
        m_limit(1000)
        { m_limit = arg; };
        virtual ~GroupsListArg(){};

    public:
            /**
                Number of results to return per call.
            */
        int limit()const{return m_limit;};
        GroupsListArg& setLimit(const int& arg){m_limit=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsListArg>  create(const QByteArray& data);
            static std::unique_ptr<GroupsListArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Number of results to return per call.
            */
        int m_limit = {0};

    };//GroupsListArg

}//team
}//dropboxQt
