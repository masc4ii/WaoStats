/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMemberSelector.h"
#include "dropbox/sharing/SharingFileMemberActionIndividualResult.h"

namespace dropboxQt{
namespace sharing{
    class FileMemberActionResult{
        /**
            Per-member result for :meth:`remove_file_member_2` or
            :meth:`add_file_member` or :meth:`change_file_member_access`.

            field: member: One of specified input members.
            field: result: The outcome of the action on this member.
        */

    public:
        FileMemberActionResult(){};

        FileMemberActionResult(const MemberSelector& arg){ m_member = arg; };
        virtual ~FileMemberActionResult(){};

    public:
            /**
                One of specified input members.
            */
        const MemberSelector& member()const{return m_member;};

            /**
                The outcome of the action on this member.
            */
        const FileMemberActionIndividualResult& result()const{return m_result;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FileMemberActionResult>  create(const QByteArray& data);
            static std::unique_ptr<FileMemberActionResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                One of specified input members.
            */
        MemberSelector m_member;

            /**
                The outcome of the action on this member.
            */
        FileMemberActionIndividualResult m_result;

    };//FileMemberActionResult

}//sharing
}//dropboxQt
