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
    class ListFolderGetLatestCursorResult{
        /**
            field: cursor: Pass the cursor into :meth:`list_folder_continue` to
                see what's changed in the folder since your previous query.
        */

    public:
        ListFolderGetLatestCursorResult(){};

        ListFolderGetLatestCursorResult(const QString& arg){ m_cursor = arg; };
        virtual ~ListFolderGetLatestCursorResult(){};

    public:
            /**
                Pass the cursor into :meth:`list_folder_continue` to see what's
                changed in the folder since your previous query.
            */
        QString cursor()const{return m_cursor;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderGetLatestCursorResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderGetLatestCursorResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Pass the cursor into :meth:`list_folder_continue` to see what's
                changed in the folder since your previous query.
            */
        QString m_cursor;

    };//ListFolderGetLatestCursorResult

}//files
}//dropboxQt
