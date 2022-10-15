/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMemberAddArg.h"

namespace dropboxQt{
namespace team{
    class MembersAddArg{
        /**
            field: new_members: Details of new members to be added to the team.
            field: force_async: Whether to force the add to happen
                asynchronously.
        */

    public:
        MembersAddArg():
        m_force_async(false)
        {};

        MembersAddArg(const std::list <MemberAddArg>& arg):
        m_force_async(false)
        { m_new_members = arg; };
        virtual ~MembersAddArg(){};

    public:
            /**
                Details of new members to be added to the team.
            */
        const std::list <MemberAddArg>& newMembers()const{return m_new_members;};
        MembersAddArg& setNewmembers(const std::list <MemberAddArg>& arg){m_new_members=arg;return *this;};

            /**
                Whether to force the add to happen asynchronously.
            */
        bool forceAsync()const{return m_force_async;};
        MembersAddArg& setForceasync(const bool& arg){m_force_async=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersAddArg>  create(const QByteArray& data);
            static std::unique_ptr<MembersAddArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Details of new members to be added to the team.
            */
        std::list <MemberAddArg> m_new_members;

            /**
                Whether to force the add to happen asynchronously.
            */
        bool m_force_async;

    };//MembersAddArg

}//team
}//dropboxQt
