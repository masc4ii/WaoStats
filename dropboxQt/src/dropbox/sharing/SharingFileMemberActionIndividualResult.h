/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingAccessLevel.h"
#include "dropbox/sharing/SharingFileMemberActionError.h"

namespace dropboxQt{
namespace sharing{
    class FileMemberActionIndividualResult{
        /**
            field: success: Member was successfully removed from this file. If
                AccessLevel is given, the member still has access via a parent
                shared folder.
            field: member_error: User was not able to perform this action.
        */
    public:
        enum Tag{

        /*Member was successfully removed from this file. If AccessLevel is given, the member still has access via a parent shared folder.*/
        FileMemberActionIndividualResult_SUCCESS,
        /*User was not able to perform this action.*/
        FileMemberActionIndividualResult_MEMBER_ERROR
        };

        FileMemberActionIndividualResult(){}
        FileMemberActionIndividualResult(Tag v):m_tag(v){}
        virtual ~FileMemberActionIndividualResult(){}

        Tag tag()const{return m_tag;}
        ///Member was successfully removed from this file. If AccessLevel is given, the member still has access via a parent shared folder.
        const AccessLevel& getSuccess()const{API_CHECK_STATE((FileMemberActionIndividualResult_SUCCESS == m_tag), "expected tag: FileMemberActionIndividualResult_SUCCESS", m_tag);return m_success;};

        ///User was not able to perform this action.
        const FileMemberActionError& getMemberError()const{API_CHECK_STATE((FileMemberActionIndividualResult_MEMBER_ERROR == m_tag), "expected tag: FileMemberActionIndividualResult_MEMBER_ERROR", m_tag);return m_member_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FileMemberActionIndividualResult>  create(const QByteArray& data);
            static std::unique_ptr<FileMemberActionIndividualResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        AccessLevel m_success;
        FileMemberActionError m_member_error;
    };//FileMemberActionIndividualResult

}//sharing
}//dropboxQt
