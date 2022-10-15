/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamUserSelectorArg.h"

namespace dropboxQt{
namespace team{
    class MembersGetInfoArgs{
        /**
            field: members: List of team members.
        */

    public:
        MembersGetInfoArgs(){};

        MembersGetInfoArgs(const std::list <UserSelectorArg>& arg){ m_members = arg; };
        virtual ~MembersGetInfoArgs(){};

    public:
            /**
                List of team members.
            */
        const std::list <UserSelectorArg>& members()const{return m_members;};
        MembersGetInfoArgs& setMembers(const std::list <UserSelectorArg>& arg){m_members=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersGetInfoArgs>  create(const QByteArray& data);
            static std::unique_ptr<MembersGetInfoArgs>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of team members.
            */
        std::list <UserSelectorArg> m_members;

    };//MembersGetInfoArgs

}//team
}//dropboxQt
