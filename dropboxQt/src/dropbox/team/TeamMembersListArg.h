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
    class MembersListArg{
        /**
            field: limit: Number of results to return per call.
            field: include_removed: Whether to return removed members.
        */

    public:
        MembersListArg():
        m_limit(1000)
        ,m_include_removed(false)
        {};

        MembersListArg(const int& arg):
        m_limit(1000)
        ,m_include_removed(false)
        { m_limit = arg; };
        virtual ~MembersListArg(){};

    public:
            /**
                Number of results to return per call.
            */
        int limit()const{return m_limit;};
        MembersListArg& setLimit(const int& arg){m_limit=arg;return *this;};

            /**
                Whether to return removed members.
            */
        bool includeRemoved()const{return m_include_removed;};
        MembersListArg& setIncluderemoved(const bool& arg){m_include_removed=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersListArg>  create(const QByteArray& data);
            static std::unique_ptr<MembersListArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Number of results to return per call.
            */
        int m_limit = {0};

            /**
                Whether to return removed members.
            */
        bool m_include_removed;

    };//MembersListArg

}//team
}//dropboxQt
