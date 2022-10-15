/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharingFileAccessError.h"

namespace dropboxQt{
namespace sharing{
    class FileMemberActionError{
        /**
            field: invalid_member: Specified member was not found.
            field: no_permission: User does not have permission to perform this
                action on this member.
            field: access_error: Specified file was invalid or user does not
                have access.
        */
    public:
        enum Tag{

        /*Specified member was not found.*/
        FileMemberActionError_INVALID_MEMBER,
        /*User does not have permission to perform this action on this member.*/
        FileMemberActionError_NO_PERMISSION,
        /*Specified file was invalid or user does not have access.*/
        FileMemberActionError_ACCESS_ERROR,
        /*None*/
        FileMemberActionError_OTHER
        };

        FileMemberActionError(){}
        FileMemberActionError(Tag v):m_tag(v){}
        virtual ~FileMemberActionError(){}

        Tag tag()const{return m_tag;}
        ///Specified file was invalid or user does not have access.
        const SharingFileAccessError& getAccessError()const{API_CHECK_STATE((FileMemberActionError_ACCESS_ERROR == m_tag), "expected tag: FileMemberActionError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<FileMemberActionError>  create(const QByteArray& data);
            static std::unique_ptr<FileMemberActionError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharingFileAccessError m_access_error;
    };//FileMemberActionError

}//sharing
}//dropboxQt
