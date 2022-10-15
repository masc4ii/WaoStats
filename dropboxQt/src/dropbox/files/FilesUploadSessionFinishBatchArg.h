/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesUploadSessionFinishArg.h"

namespace dropboxQt{
namespace files{
    class UploadSessionFinishBatchArg{
        /**
            field: entries: Commit information for each file in the batch.
        */

    public:
        UploadSessionFinishBatchArg(){};

        UploadSessionFinishBatchArg(const std::list <UploadSessionFinishArg>& arg){ m_entries = arg; };
        virtual ~UploadSessionFinishBatchArg(){};

    public:
            /**
                Commit information for each file in the batch.
            */
        const std::list <UploadSessionFinishArg>& entries()const{return m_entries;};
        UploadSessionFinishBatchArg& setEntries(const std::list <UploadSessionFinishArg>& arg){m_entries=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionFinishBatchArg>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionFinishBatchArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Commit information for each file in the batch.
            */
        std::list <UploadSessionFinishArg> m_entries;

    };//UploadSessionFinishBatchArg

}//files
}//dropboxQt
