/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMembershipInfo.h"
#include "dropbox/sharing/SharingGroupInfo.h"

namespace dropboxQt{
namespace sharing{
    class GroupMembershipInfo : public MembershipInfo{
        /**
            The information about a group member of the shared content.

            field: group: The information about the membership group.
        */

    public:
        GroupMembershipInfo(){};

        GroupMembershipInfo(const GroupInfo& arg){ m_group = arg; };
        virtual ~GroupMembershipInfo(){};

    public:
            /**
                The information about the membership group.
            */
        const GroupInfo& group()const{return m_group;};
        GroupMembershipInfo& setGroup(const GroupInfo& arg){m_group=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupMembershipInfo>  create(const QByteArray& data);
            static std::unique_ptr<GroupMembershipInfo>  create(const QJsonObject& js);
        };



    protected:
            /**
                The information about the membership group.
            */
        GroupInfo m_group;

    };//GroupMembershipInfo

}//sharing
}//dropboxQt
