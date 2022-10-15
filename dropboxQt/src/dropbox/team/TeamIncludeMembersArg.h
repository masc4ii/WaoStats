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
    class IncludeMembersArg{
        /**
            field: return_members: Whether to return the list of members in the
                group.  Note that the default value will cause all the group
                members  to be returned in the response. This may take a long
                time for large groups.
        */

    public:
        IncludeMembersArg():
        m_return_members(false)
        {};

        IncludeMembersArg(const bool& arg):
        m_return_members(false)
        { m_return_members = arg; };
        virtual ~IncludeMembersArg(){};

    public:
            /**
                Whether to return the list of members in the group.  Note that
                the default value will cause all the group members  to be
                returned in the response. This may take a long time for large
                groups.
            */
        bool returnMembers()const{return m_return_members;};
        IncludeMembersArg& setReturnmembers(const bool& arg){m_return_members=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<IncludeMembersArg>  create(const QByteArray& data);
            static std::unique_ptr<IncludeMembersArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Whether to return the list of members in the group.  Note that
                the default value will cause all the group members  to be
                returned in the response. This may take a long time for large
                groups.
            */
        bool m_return_members;

    };//IncludeMembersArg

}//team
}//dropboxQt
