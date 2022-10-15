/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/async/AsyncPollResultBase.h"
#include "dropbox/sharing/SharingJobError.h"

namespace dropboxQt{
namespace sharing{
    class JobStatus{
        /**
            field: complete: The asynchronous job has finished.
            field: failed: The asynchronous job returned an error.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS,
        /*The asynchronous job has finished.*/
        JobStatus_COMPLETE,
        /*The asynchronous job returned an error.*/
        JobStatus_FAILED
        };

        JobStatus(){}
        JobStatus(Tag v):m_tag(v){}
        virtual ~JobStatus(){}

        Tag tag()const{return m_tag;}
        ///The asynchronous job returned an error.
        const JobError& getFailed()const{API_CHECK_STATE((JobStatus_FAILED == m_tag), "expected tag: JobStatus_FAILED", m_tag);return m_failed;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<JobStatus>  create(const QByteArray& data);
            static std::unique_ptr<JobStatus>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        JobError m_failed;
    };//JobStatus

}//sharing
}//dropboxQt
