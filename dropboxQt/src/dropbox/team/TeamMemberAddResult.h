/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamTeamMemberInfo.h"

namespace dropboxQt{
namespace team{
    class MemberAddResult{
        /**
            Describes the result of attempting to add a single user to the team.
            'success' is the only value indicating that a user was indeed added
            to the team - the other values explain the type of failure that
            occurred, and include the email of the user for which the operation
            has failed.

            field: success: Describes a user that was successfully added to the
                team.
            field: team_license_limit: Team is already full. The organization
                has no available licenses.
            field: free_team_member_limit_reached: Team is already full. The
                free team member limit has been reached.
            field: user_already_on_team: User is already on this team. The
                provided email address is associated with a user who is already
                a member of (including in recoverable state) or invited to the
                team.
            field: user_on_another_team: User is already on another team. The
                provided email address is associated with a user that is already
                a member or invited to another team.
            field: user_already_paired: User is already paired.
            field: user_migration_failed: User migration has failed.
            field: duplicate_external_member_id: A user with the given external
                member ID already exists on the team (including in recoverable
                state).
            field: user_creation_failed: User creation has failed.
        */
    public:
        enum Tag{

        /*Describes a user that was successfully added to the team.*/
        MemberAddResult_SUCCESS,
        /*Team is already full. The organization has no available licenses.*/
        MemberAddResult_TEAM_LICENSE_LIMIT,
        /*Team is already full. The free team member limit has been reached.*/
        MemberAddResult_FREE_TEAM_MEMBER_LIMIT_REACHED,
        /*User is already on this team. The provided email address is associated with a user who is already a member of (including in recoverable state) or invited to the team.*/
        MemberAddResult_USER_ALREADY_ON_TEAM,
        /*User is already on another team. The provided email address is associated with a user that is already a member or invited to another team.*/
        MemberAddResult_USER_ON_ANOTHER_TEAM,
        /*User is already paired.*/
        MemberAddResult_USER_ALREADY_PAIRED,
        /*User migration has failed.*/
        MemberAddResult_USER_MIGRATION_FAILED,
        /*A user with the given external member ID already exists on the team (including in recoverable state).*/
        MemberAddResult_DUPLICATE_EXTERNAL_MEMBER_ID,
        /*User creation has failed.*/
        MemberAddResult_USER_CREATION_FAILED
        };

        MemberAddResult(){}
        MemberAddResult(Tag v):m_tag(v){}
        virtual ~MemberAddResult(){}

        Tag tag()const{return m_tag;}
        ///Describes a user that was successfully added to the team.
        const TeamMemberInfo& getSuccess()const{API_CHECK_STATE((MemberAddResult_SUCCESS == m_tag), "expected tag: MemberAddResult_SUCCESS", m_tag);return m_success;};

        ///Team is already full. The organization has no available licenses.
        QString getTeamLicenseLimit()const{API_CHECK_STATE((MemberAddResult_TEAM_LICENSE_LIMIT == m_tag), "expected tag: MemberAddResult_TEAM_LICENSE_LIMIT", m_tag);return m_team_license_limit;};

        ///Team is already full. The free team member limit has been reached.
        QString getFreeTeamMemberLimitReached()const{API_CHECK_STATE((MemberAddResult_FREE_TEAM_MEMBER_LIMIT_REACHED == m_tag), "expected tag: MemberAddResult_FREE_TEAM_MEMBER_LIMIT_REACHED", m_tag);return m_free_team_member_limit_reached;};

        ///User is already on this team. The provided email address is associated with a user who is already a member of (including in recoverable state) or invited to the team.
        QString getUserAlreadyOnTeam()const{API_CHECK_STATE((MemberAddResult_USER_ALREADY_ON_TEAM == m_tag), "expected tag: MemberAddResult_USER_ALREADY_ON_TEAM", m_tag);return m_user_already_on_team;};

        ///User is already on another team. The provided email address is associated with a user that is already a member or invited to another team.
        QString getUserOnAnotherTeam()const{API_CHECK_STATE((MemberAddResult_USER_ON_ANOTHER_TEAM == m_tag), "expected tag: MemberAddResult_USER_ON_ANOTHER_TEAM", m_tag);return m_user_on_another_team;};

        ///User is already paired.
        QString getUserAlreadyPaired()const{API_CHECK_STATE((MemberAddResult_USER_ALREADY_PAIRED == m_tag), "expected tag: MemberAddResult_USER_ALREADY_PAIRED", m_tag);return m_user_already_paired;};

        ///User migration has failed.
        QString getUserMigrationFailed()const{API_CHECK_STATE((MemberAddResult_USER_MIGRATION_FAILED == m_tag), "expected tag: MemberAddResult_USER_MIGRATION_FAILED", m_tag);return m_user_migration_failed;};

        ///A user with the given external member ID already exists on the team (including in recoverable state).
        QString getDuplicateExternalMemberId()const{API_CHECK_STATE((MemberAddResult_DUPLICATE_EXTERNAL_MEMBER_ID == m_tag), "expected tag: MemberAddResult_DUPLICATE_EXTERNAL_MEMBER_ID", m_tag);return m_duplicate_external_member_id;};

        ///User creation has failed.
        QString getUserCreationFailed()const{API_CHECK_STATE((MemberAddResult_USER_CREATION_FAILED == m_tag), "expected tag: MemberAddResult_USER_CREATION_FAILED", m_tag);return m_user_creation_failed;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MemberAddResult>  create(const QByteArray& data);
            static std::unique_ptr<MemberAddResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        TeamMemberInfo m_success;
        QString m_team_license_limit;
        QString m_free_team_member_limit_reached;
        QString m_user_already_on_team;
        QString m_user_on_another_team;
        QString m_user_already_paired;
        QString m_user_migration_failed;
        QString m_duplicate_external_member_id;
        QString m_user_creation_failed;
    };//MemberAddResult

}//team
}//dropboxQt
