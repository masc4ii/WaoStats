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
    class AdminTier{
        /**
            Describes which team-related admin permissions a user has.

            field: team_admin: User is an administrator of the team - has all
                permissions.
            field: user_management_admin: User can do most user provisioning,
                de-provisioning and management.
            field: support_admin: User can do a limited set of common support
                tasks for existing users.
            field: member_only: User is not an admin of the team.
        */
    public:
        enum Tag{

        /*User is an administrator of the team - has all permissions.*/
        AdminTier_TEAM_ADMIN,
        /*User can do most user provisioning, de-provisioning and management.*/
        AdminTier_USER_MANAGEMENT_ADMIN,
        /*User can do a limited set of common support tasks for existing users.*/
        AdminTier_SUPPORT_ADMIN,
        /*User is not an admin of the team.*/
        AdminTier_MEMBER_ONLY
        };

        AdminTier(){}
        AdminTier(Tag v):m_tag(v){}
        virtual ~AdminTier(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AdminTier>  create(const QByteArray& data);
            static std::unique_ptr<AdminTier>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//AdminTier

}//team
}//dropboxQt
