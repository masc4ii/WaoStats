/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace sharing{
    class SharedFolderAccessError{
        /**
            There is an error accessing the shared folder.

            field: invalid_id: This shared folder ID is invalid.
            field: not_a_member: The user is not a member of the shared folder
                thus cannot access it.
            field: email_unverified: The current user's e-mail address is
                unverified.
            field: unmounted: The shared folder is unmounted.
        */
    public:
        enum Tag{

        /*This shared folder ID is invalid.*/
        SharedFolderAccessError_INVALID_ID,
        /*The user is not a member of the shared folder thus cannot access it.*/
        SharedFolderAccessError_NOT_A_MEMBER,
        /*The current user's e-mail address is unverified.*/
        SharedFolderAccessError_EMAIL_UNVERIFIED,
        /*The shared folder is unmounted.*/
        SharedFolderAccessError_UNMOUNTED,
        /*None*/
        SharedFolderAccessError_OTHER
        };

        SharedFolderAccessError(){}
        SharedFolderAccessError(Tag v):m_tag(v){}
        virtual ~SharedFolderAccessError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SharedFolderAccessError>  create(const QByteArray& data);
            static std::unique_ptr<SharedFolderAccessError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//SharedFolderAccessError

}//sharing
}//dropboxQt
