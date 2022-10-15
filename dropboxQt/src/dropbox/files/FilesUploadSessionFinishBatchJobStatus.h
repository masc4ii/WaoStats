/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/async/AsyncPollResultBase.h"
#include "dropbox/files/FilesUploadSessionFinishBatchResult.h"

namespace dropboxQt{
namespace files{
    class UploadSessionFinishBatchJobStatus{
        /**
            field: complete: The :meth:`upload_session_finish_batch` has
                finished.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS,
        /*The :route:`upload_session/finish_batch` has finished.*/
        UploadSessionFinishBatchJobStatus_COMPLETE
        };

        UploadSessionFinishBatchJobStatus(){}
        UploadSessionFinishBatchJobStatus(Tag v):m_tag(v){}
        virtual ~UploadSessionFinishBatchJobStatus(){}

        Tag tag()const{return m_tag;}
        ///The :route:`upload_session/finish_batch` has finished.
        const UploadSessionFinishBatchResult& getComplete()const{API_CHECK_STATE((UploadSessionFinishBatchJobStatus_COMPLETE == m_tag), "expected tag: UploadSessionFinishBatchJobStatus_COMPLETE", m_tag);return m_complete;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionFinishBatchJobStatus>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionFinishBatchJobStatus>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        UploadSessionFinishBatchResult m_complete;
    };//UploadSessionFinishBatchJobStatus

}//files
}//dropboxQt
