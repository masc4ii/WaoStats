/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace async{
    class PollError{
        /**
            Error returned by methods for polling the status of asynchronous
            job.

            field: invalid_async_job_id: The job ID is invalid.
            field: internal_error: Something went wrong with the job on
                Dropbox's end. You'll need to verify that the action you were
                taking succeeded, and if not, try again. This should happen very
                rarely.
        */
    public:
        enum Tag{

        /*The job ID is invalid.*/
        PollError_INVALID_ASYNC_JOB_ID,
        /*Something went wrong with the job on Dropbox's end. You'll need to verify that the action you were taking succeeded, and if not, try again. This should happen very rarely.*/
        PollError_INTERNAL_ERROR,
        /*None*/
        PollError_OTHER
        };

        PollError(){}
        PollError(Tag v):m_tag(v){}
        virtual ~PollError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PollError>  create(const QByteArray& data);
            static std::unique_ptr<PollError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//PollError

}//async
}//dropboxQt
