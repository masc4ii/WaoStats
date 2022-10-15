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
    class ListFolderLongpollResult{
        /**
            field: changes: Indicates whether new changes are available. If
                true, call :meth:`list_folder_continue` to retrieve the changes.
            field: backoff: If present, backoff for at least this many seconds
                before calling :meth:`list_folder_longpoll` again.
        */

    public:
        ListFolderLongpollResult(){};

        ListFolderLongpollResult(const bool& arg){ m_changes = arg; };
        virtual ~ListFolderLongpollResult(){};

    public:
            /**
                Indicates whether new changes are available. If true, call
                :meth:`list_folder_continue` to retrieve the changes.
            */
        bool changes()const{return m_changes;};

            /**
                If present, backoff for at least this many seconds before
                calling :meth:`list_folder_longpoll` again.
            */
        int backoff()const{return m_backoff;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFolderLongpollResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFolderLongpollResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Indicates whether new changes are available. If true, call
                :meth:`list_folder_continue` to retrieve the changes.
            */
        bool m_changes;

            /**
                If present, backoff for at least this many seconds before
                calling :meth:`list_folder_longpoll` again.
            */
        int m_backoff;

    };//ListFolderLongpollResult

}//files
}//dropboxQt
