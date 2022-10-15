/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupFullInfo.h"

namespace dropboxQt{
namespace team{
    class GroupMembersChangeResult{
        /**
            Result returned by :meth:`groups_members_add` and
            :meth:`groups_members_remove`.

            field: group_info: The group info after member change operation has
                been performed.
            field: async_job_id: An ID that can be used to obtain the status of
                granting/revoking group-owned resources.
        */

    public:
        GroupMembersChangeResult(){};

        GroupMembersChangeResult(const GroupFullInfo& arg){ m_group_info = arg; };
        virtual ~GroupMembersChangeResult(){};

    public:
            /**
                The group info after member change operation has been performed.
            */
        const GroupFullInfo& groupInfo()const{return m_group_info;};

            /**
                An ID that can be used to obtain the status of granting/revoking
                group-owned resources.
            */
        QString asyncJobId()const{return m_async_job_id;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembersChangeResult>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembersChangeResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                The group info after member change operation has been performed.
            */
        GroupFullInfo m_group_info;

            /**
                An ID that can be used to obtain the status of granting/revoking
                group-owned resources.
            */
        QString m_async_job_id;

    };//GroupMembersChangeResult

}//team
}//dropboxQt
