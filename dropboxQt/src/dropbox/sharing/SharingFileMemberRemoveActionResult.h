/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingMemberAccessLevelResult.h"
#include "dropbox/sharing/SharingFileMemberActionError.h"

namespace dropboxQt{
namespace sharing{
    class FileMemberRemoveActionResult{
        /**
            field: success: Member was successfully removed from this file.
            field: member_error: User was not able to remove this member.
        */
    public:
        enum Tag{

        /*Member was successfully removed from this file.*/
        FileMemberRemoveActionResult_SUCCESS,
        /*User was not able to remove this member.*/
        FileMemberRemoveActionResult_MEMBER_ERROR,
        /*None*/
        FileMemberRemoveActionResult_OTHER
        };

        FileMemberRemoveActionResult(){}
        FileMemberRemoveActionResult(Tag v):m_tag(v){}
        virtual ~FileMemberRemoveActionResult(){}

        Tag tag()const{return m_tag;}
        ///Member was successfully removed from this file.
        const MemberAccessLevelResult& getSuccess()const{API_CHECK_STATE((FileMemberRemoveActionResult_SUCCESS == m_tag), "expected tag: FileMemberRemoveActionResult_SUCCESS", m_tag);return m_success;};

        ///User was not able to remove this member.
        const FileMemberActionError& getMemberError()const{API_CHECK_STATE((FileMemberRemoveActionResult_MEMBER_ERROR == m_tag), "expected tag: FileMemberRemoveActionResult_MEMBER_ERROR", m_tag);return m_member_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FileMemberRemoveActionResult>  create(const QByteArray& data);
            static std::unique_ptr<FileMemberRemoveActionResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        MemberAccessLevelResult m_success;
        FileMemberActionError m_member_error;
    };//FileMemberRemoveActionResult

}//sharing
}//dropboxQt
