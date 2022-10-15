/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace files{
    class ListFolderContinueArg{
        /**
            field: cursor: The cursor returned by your last call to
                :meth:`list_folder` or :meth:`list_folder_continue`.
        */

    public:
        ListFolderContinueArg(){};

        ListFolderContinueArg(const QString& arg){ m_cursor = arg; };
        virtual ~ListFolderContinueArg(){};

    public:
            /**
                The cursor returned by your last call to :meth:`list_folder` or
                :meth:`list_folder_continue`.
            */
        QString cursor()const{return m_cursor;};
        ListFolderContinueArg& setCursor(const QString& arg){m_cursor=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderContinueArg>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderContinueArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                The cursor returned by your last call to :meth:`list_folder` or
                :meth:`list_folder_continue`.
            */
        QString m_cursor;

    };//ListFolderContinueArg

}//files
}//dropboxQt
