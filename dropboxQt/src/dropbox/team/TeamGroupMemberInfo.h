/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamMemberProfile.h"
#include "dropbox/team/TeamGroupAccessType.h"

namespace dropboxQt{
namespace team{
    class GroupMemberInfo{
        /**
            Profile of group member, and role in group.

            field: profile: Profile of group member.
            field: access_type: The role that the user has in the group.
        */

    public:
        GroupMemberInfo(){};

        GroupMemberInfo(const MemberProfile& arg){ m_profile = arg; };
        virtual ~GroupMemberInfo(){};

    public:
            /**
                Profile of group member.
            */
        const MemberProfile& profile()const{return m_profile;};
        GroupMemberInfo& setProfile(const MemberProfile& arg){m_profile=arg;return *this;};

            /**
                The role that the user has in the group.
            */
        const GroupAccessType& accessType()const{return m_access_type;};
        GroupMemberInfo& setAccesstype(const GroupAccessType& arg){m_access_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMemberInfo>  create(const QByteArray& data);
            static std::unique_ptr<GroupMemberInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                Profile of group member.
            */
        MemberProfile m_profile;

            /**
                The role that the user has in the group.
            */
        GroupAccessType m_access_type;

    };//GroupMemberInfo

}//team
}//dropboxQt
