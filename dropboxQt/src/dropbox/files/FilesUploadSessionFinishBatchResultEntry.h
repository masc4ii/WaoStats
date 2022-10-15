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
#include "dropbox/files/FilesUploadSessionFinishError.h"

namespace dropboxQt{
namespace files{
    class UploadSessionFinishBatchResultEntry{
    public:
        enum Tag{

        /*None*/
        UploadSessionFinishBatchResultEntry_SUCCESS,
        /*None*/
        UploadSessionFinishBatchResultEntry_FAILURE
        };

        UploadSessionFinishBatchResultEntry(){}
        UploadSessionFinishBatchResultEntry(Tag v):m_tag(v){}
        virtual ~UploadSessionFinishBatchResultEntry(){}

        Tag tag()const{return m_tag;}
        ///None
        const FileMetadata& getSuccess()const{API_CHECK_STATE((UploadSessionFinishBatchResultEntry_SUCCESS == m_tag), "expected tag: UploadSessionFinishBatchResultEntry_SUCCESS", m_tag);return m_success;};

        ///None
        const UploadSessionFinishError& getFailure()const{API_CHECK_STATE((UploadSessionFinishBatchResultEntry_FAILURE == m_tag), "expected tag: UploadSessionFinishBatchResultEntry_FAILURE", m_tag);return m_failure;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionFinishBatchResultEntry>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionFinishBatchResultEntry>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        FileMetadata m_success;
        UploadSessionFinishError m_failure;
    };//UploadSessionFinishBatchResultEntry

}//files
}//dropboxQt
