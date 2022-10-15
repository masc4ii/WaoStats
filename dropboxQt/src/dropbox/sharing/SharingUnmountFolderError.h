/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFolderAccessError.h"

namespace dropboxQt{
namespace sharing{
    class UnmountFolderError{
        /**
            field: no_permission: The current user does not have permission to
                perform this action.
            field: not_unmountable: The shared folder can't be unmounted. One
                example where this can occur is when the shared folder's parent
                folder is also a shared folder that resides in the current
                user's Dropbox.
        */
    public:
        enum Tag{

        /*None*/
        UnmountFolderError_ACCESS_ERROR,
        /*The current user does not have permission to perform this action.*/
        UnmountFolderError_NO_PERMISSION,
        /*The shared folder can't be unmounted. One example where this can occur is when the shared folder's parent folder is also a shared folder that resides in the current user's Dropbox.*/
        UnmountFolderError_NOT_UNMOUNTABLE,
        /*None*/
        UnmountFolderError_OTHER
        };

        UnmountFolderError(){}
        UnmountFolderError(Tag v):m_tag(v){}
        virtual ~UnmountFolderError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharedFolderAccessError& getAccessError()const{API_CHECK_STATE((UnmountFolderError_ACCESS_ERROR == m_tag), "expected tag: UnmountFolderError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UnmountFolderError>  create(const QByteArray& data);
            static std::unique_ptr<UnmountFolderError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderAccessError m_access_error;
    };//UnmountFolderError

}//sharing
}//dropboxQt
