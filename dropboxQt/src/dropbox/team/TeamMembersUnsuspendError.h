/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMembersDeactivateError.h"

namespace dropboxQt{
namespace team{
    class MembersUnsuspendError{
        /**
            field: unsuspend_non_suspended_member: The user is unsuspended, so
                it cannot be unsuspended again.
            field: team_license_limit: Team is full. The organization has no
                available licenses.
        */
    public:
        enum Tag{

        /*No matching user found. The provided team_member_id, email, or external_id does not exist on this team.*/
        UserSelectorError_USER_NOT_FOUND,
        /*The user is not a member of the team.*/
        MembersDeactivateError_USER_NOT_IN_TEAM,
        /*None*/
        MembersDeactivateError_OTHER,
        /*The user is unsuspended, so it cannot be unsuspended again.*/
        MembersUnsuspendError_UNSUSPEND_NON_SUSPENDED_MEMBER,
        /*Team is full. The organization has no available licenses.*/
        MembersUnsuspendError_TEAM_LICENSE_LIMIT
        };

        MembersUnsuspendError(){}
        MembersUnsuspendError(Tag v):m_tag(v){}
        virtual ~MembersUnsuspendError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersUnsuspendError>  create(const QByteArray& data);
            static std::unique_ptr<MembersUnsuspendError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//MembersUnsuspendError

}//team
}//dropboxQt
