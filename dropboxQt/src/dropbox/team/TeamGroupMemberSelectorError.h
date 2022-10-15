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
    class GroupMemberSelectorError{
        /**
            Error that can be raised when :class:`GroupMemberSelector` is used,
            and the user is required to be a member of the specified group.

            field: member_not_in_group: The specified user is not a member of
                this group.
        */
    public:
        enum Tag{

        /*No matching group found. No groups match the specified group ID.*/
        GroupSelectorError_GROUP_NOT_FOUND,
        /*None*/
        GroupSelectorError_OTHER,
        /*The specified user is not a member of this group.*/
        GroupMemberSelectorError_MEMBER_NOT_IN_GROUP
        };

        GroupMemberSelectorError(){}
        GroupMemberSelectorError(Tag v):m_tag(v){}
        virtual ~GroupMemberSelectorError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMemberSelectorError>  create(const QByteArray& data);
            static std::unique_ptr<GroupMemberSelectorError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupMemberSelectorError

}//team
}//dropboxQt
