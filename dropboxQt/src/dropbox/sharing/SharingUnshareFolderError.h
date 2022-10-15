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
    class UnshareFolderError{
        /**
            field: team_folder: This action cannot be performed on a team shared
                folder.
            field: no_permission: The current user does not have permission to
                perform this action.
        */
    public:
        enum Tag{

        /*None*/
        UnshareFolderError_ACCESS_ERROR,
        /*This action cannot be performed on a team shared folder.*/
        UnshareFolderError_TEAM_FOLDER,
        /*The current user does not have permission to perform this action.*/
        UnshareFolderError_NO_PERMISSION,
        /*None*/
        UnshareFolderError_OTHER
        };

        UnshareFolderError(){}
        UnshareFolderError(Tag v):m_tag(v){}
        virtual ~UnshareFolderError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharedFolderAccessError& getAccessError()const{API_CHECK_STATE((UnshareFolderError_ACCESS_ERROR == m_tag), "expected tag: UnshareFolderError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UnshareFolderError>  create(const QByteArray& data);
            static std::unique_ptr<UnshareFolderError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderAccessError m_access_error;
    };//UnshareFolderError

}//sharing
}//dropboxQt
