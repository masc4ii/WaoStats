/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesFileMetadata.h"

namespace dropboxQt{
namespace files{
    class ListRevisionsResult{
        /**
            field: is_deleted: If the file is deleted.
            field: entries: The revisions for the file. Only non-delete
                revisions will show up here.
        */

    public:
        ListRevisionsResult(){};

        ListRevisionsResult(const bool& arg){ m_is_deleted = arg; };
        virtual ~ListRevisionsResult(){};

    public:
            /**
                If the file is deleted.
            */
        bool isDeleted()const{return m_is_deleted;};

            /**
                The revisions for the file. Only non-delete revisions will show
                up here.
            */
        const std::list <FileMetadata>& entries()const{return m_entries;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListRevisionsResult>  create(const QByteArray& data);
            static std::unique_ptr<ListRevisionsResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                If the file is deleted.
            */
        bool m_is_deleted;

            /**
                The revisions for the file. Only non-delete revisions will show
                up here.
            */
        std::list <FileMetadata> m_entries;

    };//ListRevisionsResult

}//files
}//dropboxQt
