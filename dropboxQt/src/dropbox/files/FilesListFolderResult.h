/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesMetadata.h"

namespace dropboxQt{
namespace files{
    class ListFolderResult{
        /**
            field: entries: The files and (direct) subfolders in the folder.
            field: cursor: Pass the cursor into :meth:`list_folder_continue` to
                see what's changed in the folder since your previous query.
            field: has_more: If true, then there are more entries available.
                Pass the cursor to :meth:`list_folder_continue` to retrieve the
                rest.
        */

    public:
        ListFolderResult(){};


    public:
            /**
                The files and (direct) subfolders in the folder.
            */
        const std::list <std::unique_ptr<Metadata> >& entries()const{return m_entries;};

            /**
                Pass the cursor into :meth:`list_folder_continue` to see what's
                changed in the folder since your previous query.
            */
        QString cursor()const{return m_cursor;};

            /**
                If true, then there are more entries available. Pass the cursor
                to :meth:`list_folder_continue` to retrieve the rest.
            */
        bool hasMore()const{return m_has_more;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                The files and (direct) subfolders in the folder.
            */
        std::list <std::unique_ptr<Metadata> > m_entries;

            /**
                Pass the cursor into :meth:`list_folder_continue` to see what's
                changed in the folder since your previous query.
            */
        QString m_cursor;

            /**
                If true, then there are more entries available. Pass the cursor
                to :meth:`list_folder_continue` to retrieve the rest.
            */
        bool m_has_more;

    };//ListFolderResult

}//files
}//dropboxQt
