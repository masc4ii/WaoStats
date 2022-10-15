/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesUploadSessionFinishBatchResultEntry.h"

namespace dropboxQt{
namespace files{
    class UploadSessionFinishBatchResult{
        /**
            field: entries: Commit result for each file in the batch.
        */

    public:
        UploadSessionFinishBatchResult(){};

        UploadSessionFinishBatchResult(const std::list <UploadSessionFinishBatchResultEntry>& arg){ m_entries = arg; };
        virtual ~UploadSessionFinishBatchResult(){};

    public:
            /**
                Commit result for each file in the batch.
            */
        const std::list <UploadSessionFinishBatchResultEntry>& entries()const{return m_entries;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionFinishBatchResult>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionFinishBatchResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                Commit result for each file in the batch.
            */
        std::list <UploadSessionFinishBatchResultEntry> m_entries;

    };//UploadSessionFinishBatchResult

}//files
}//dropboxQt
