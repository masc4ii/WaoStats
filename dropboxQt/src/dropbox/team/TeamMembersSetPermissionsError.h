/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamUserSelectorError.h"

namespace dropboxQt{
namespace team{
    class MembersSetPermissionsError{
        /**
            field: last_admin: Cannot remove the admin setting of the last
                admin.
            field: user_not_in_team: The user is not a member of the team.
            field: cannot_set_permissions: Cannot remove/grant permissions.
            field: team_license_limit: Team is full. The organization has no
                available licenses.
        */
    public:
        enum Tag{

        /*No matching user found. The provided team_member_id, email, or external_id does not exist on this team.*/
        UserSelectorError_USER_NOT_FOUND,
        /*Cannot remove the admin setting of the last admin.*/
        MembersSetPermissionsError_LAST_ADMIN,
        /*The user is not a member of the team.*/
        MembersSetPermissionsError_USER_NOT_IN_TEAM,
        /*Cannot remove/grant permissions.*/
        MembersSetPermissionsError_CANNOT_SET_PERMISSIONS,
        /*Team is full. The organization has no available licenses.*/
        MembersSetPermissionsError_TEAM_LICENSE_LIMIT,
        /*None*/
        MembersSetPermissionsError_OTHER
        };

        MembersSetPermissionsError(){}
        MembersSetPermissionsError(Tag v):m_tag(v){}
        virtual ~MembersSetPermissionsError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersSetPermissionsError>  create(const QByteArray& data);
            static std::unique_ptr<MembersSetPermissionsError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MembersSetPermissionsError

}//team
}//dropboxQt
