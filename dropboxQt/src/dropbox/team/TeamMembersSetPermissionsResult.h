/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamAdminTier.h"

namespace dropboxQt{
namespace team{
    class MembersSetPermissionsResult{
        /**
            field: team_member_id: The member ID of the user to which the change
                was applied.
            field: role: The role after the change.
        */

    public:
        MembersSetPermissionsResult(){};

        MembersSetPermissionsResult(const QString& arg){ m_team_member_id = arg; };
        virtual ~MembersSetPermissionsResult(){};

    public:
            /**
                The member ID of the user to which the change was applied.
            */
        QString teamMemberId()const{return m_team_member_id;};

            /**
                The role after the change.
            */
        const AdminTier& role()const{return m_role;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersSetPermissionsResult>  create(const QByteArray& data);
            static std::unique_ptr<MembersSetPermissionsResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                The member ID of the user to which the change was applied.
            */
        QString m_team_member_id;

            /**
                The role after the change.
            */
        AdminTier m_role;

    };//MembersSetPermissionsResult

}//team
}//dropboxQt
