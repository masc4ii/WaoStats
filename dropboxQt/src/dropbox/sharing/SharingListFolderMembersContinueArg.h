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
    class ListFolderMembersContinueArg{
        /**
            field: cursor: The cursor returned by your last call to
                :meth:`list_folder_members` or
                :meth:`list_folder_members_continue`.
        */

    public:
        ListFolderMembersContinueArg(){};

        ListFolderMembersContinueArg(const QString& arg){ m_cursor = arg; };
        virtual ~ListFolderMembersContinueArg(){};

    public:
            /**
                The cursor returned by your last call to
                :meth:`list_folder_members` or
                :meth:`list_folder_members_continue`.
            */
        QString cursor()const{return m_cursor;};
        ListFolderMembersContinueArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderMembersContinueArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderMembersContinueArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The cursor returned by your last call to
                :meth:`list_folder_members` or
                :meth:`list_folder_members_continue`.
            */
        QString m_cursor;

    };//ListFolderMembersContinueArg

}//sharing
}//dropboxQt
