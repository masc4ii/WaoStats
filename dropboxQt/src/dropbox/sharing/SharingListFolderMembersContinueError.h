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
    class ListFolderMembersContinueError{
        /**
            field: invalid_cursor: ``ListFolderMembersContinueArg.cursor`` is
                invalid.
        */
    public:
        enum Tag{

        /*None*/
        ListFolderMembersContinueError_ACCESS_ERROR,
        /*:field:`ListFolderMembersContinueArg.cursor` is invalid.*/
        ListFolderMembersContinueError_INVALID_CURSOR,
        /*None*/
        ListFolderMembersContinueError_OTHER
        };

        ListFolderMembersContinueError(){}
        ListFolderMembersContinueError(Tag v):m_tag(v){}
        virtual ~ListFolderMembersContinueError(){}

        Tag tag()const{return m_tag;}
        ///None
        const SharedFolderAccessError& getAccessError()const{API_CHECK_STATE((ListFolderMembersContinueError_ACCESS_ERROR == m_tag), "expected tag: ListFolderMembersContinueError_ACCESS_ERROR", m_tag);return m_access_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderMembersContinueError>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderMembersContinueError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderAccessError m_access_error;
    };//ListFolderMembersContinueError

}//sharing
}//dropboxQt
