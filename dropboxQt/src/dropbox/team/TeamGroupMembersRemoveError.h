/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupMembersSelectorError.h"

namespace dropboxQt{
namespace team{
    class GroupMembersRemoveError{
        /**
            field: group_not_in_team: Group is not in this team. You cannot
                remove members from a group that is outside of your team.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER,
        /*At least one of the specified users is not a member of the group.*/
        GroupMembersSelectorError_MEMBER_NOT_IN_GROUP,
        /*Group is not in this team. You cannot remove members from a group that is outside of your team.*/
        GroupMembersRemoveError_GROUP_NOT_IN_TEAM
        };

        GroupMembersRemoveError(){}
        GroupMembersRemoveError(Tag v):m_tag(v){}
        virtual ~GroupMembersRemoveError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembersRemoveError>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembersRemoveError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupMembersRemoveError

}//team
}//dropboxQt
