/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/sharing/SharingSharedFileMetadata.h"

namespace dropboxQt{
namespace sharing{
    class ListFilesResult{
        /**
            Success results for :meth:`list_received_files`.

            field: entries: Information about the files shared with current
                user.
            field: cursor: Cursor used to obtain additional shared files.
        */

    public:
        ListFilesResult(){};

        ListFilesResult(const std::list <SharedFileMetadata>& arg){ m_entries = arg; };
        virtual ~ListFilesResult(){};

    public:
            /**
                Information about the files shared with current user.
            */
        const std::list <SharedFileMetadata>& entries()const{return m_entries;};

            /**
                Cursor used to obtain additional shared files.
            */
        QString cursor()const{return m_cursor;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListFilesResult>  create(const QByteArray& data);
            static std::unique_ptr<ListFilesResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Information about the files shared with current user.
            */
        std::list <SharedFileMetadata> m_entries;

            /**
                Cursor used to obtain additional shared files.
            */
        QString m_cursor;

    };//ListFilesResult

}//sharing
}//dropboxQt
