/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupSelector.h"

namespace dropboxQt{
namespace team{
    class GroupsMembersListArg{
        /**
            field: group: The group whose members are to be listed.
            field: limit: Number of results to return per call.
        */

    public:
        GroupsMembersListArg():
        m_limit(1000)
        {};

        GroupsMembersListArg(const GroupSelector& arg):
        m_limit(1000)
        { m_group = arg; };
        virtual ~GroupsMembersListArg(){};

    public:
            /**
                The group whose members are to be listed.
            */
        const GroupSelector& group()const{return m_group;};
        GroupsMembersListArg& setGroup(const GroupSelector& arg){m_group=arg;return *this;};

            /**
                Number of results to return per call.
            */
        int limit()const{return m_limit;};
        GroupsMembersListArg& setLimit(const int& arg){m_limit=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsMembersListArg>  create(const QByteArray& data);
            static std::unique_ptr<GroupsMembersListArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The group whose members are to be listed.
            */
        GroupSelector m_group;

            /**
                Number of results to return per call.
            */
        int m_limit = {0};

    };//GroupsMembersListArg

}//team
}//dropboxQt
