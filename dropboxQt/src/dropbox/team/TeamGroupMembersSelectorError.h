/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/team/TeamGroupSelectorError.h"

namespace dropboxQt{
namespace team{
    class GroupMembersSelectorError{
        /**
            Error that can be raised when :class:`GroupMembersSelector` is used,
            and the users are required to be members of the specified group.

            field: member_not_in_group: At least one of the specified users is
                not a member of the group.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER,
        /*At least one of the specified users is not a member of the group.*/
        GroupMembersSelectorError_MEMBER_NOT_IN_GROUP
        };

        GroupMembersSelectorError(){}
        GroupMembersSelectorError(Tag v):m_tag(v){}
        virtual ~GroupMembersSelectorError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembersSelectorError>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembersSelectorError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupMembersSelectorError

}//team
}//dropboxQt
