/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFileMembers.h"

namespace dropboxQt{
namespace sharing{
    class ListFileMembersCountResult{
        /**
            field: members: A list of members on this file.
            field: member_count: The number of members on this file. This does
                not include inherited members
        */

    public:
        ListFileMembersCountResult(){};

        ListFileMembersCountResult(const SharedFileMembers& arg){ m_members = arg; };
        virtual ~ListFileMembersCountResult(){};

    public:
            /**
                A list of members on this file.
            */
        const SharedFileMembers& members()const{return m_members;};

            /**
                The number of members on this file. This does not include
                inherited members
            */
        int memberCount()const{return m_member_count;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFileMembersCountResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFileMembersCountResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                A list of members on this file.
            */
        SharedFileMembers m_members;

            /**
                The number of members on this file. This does not include
                inherited members
            */
        int m_member_count = {0};

    };//ListFileMembersCountResult

}//sharing
}//dropboxQt
