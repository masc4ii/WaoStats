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
    class ListMemberAppsArg{
        /**
            field: team_member_id: The team member id
        */

    public:
        ListMemberAppsArg(){};

        ListMemberAppsArg(const QString& arg){ m_team_member_id = arg; };
        virtual ~ListMemberAppsArg(){};

    public:
            /**
                The team member id
            */
        QString teamMemberId()const{return m_team_member_id;};
        ListMemberAppsArg& setTeammemberid(const QString& arg){m_team_member_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListMemberAppsArg>  create(const QByteArray& data);
            static std::unique_ptr<ListMemberAppsArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The team member id
            */
        QString m_team_member_id;

    };//ListMemberAppsArg

}//team
}//dropboxQt
