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
    class PollArg{
        /**
            Arguments for methods that poll the status of an asynchronous job.

            field: async_job_id: Id of the asynchronous job. This is the value
                of a response returned from the method that launched the job.
        */

    public:
        PollArg(){};

        PollArg(const QString& arg){ m_async_job_id = arg; };
        virtual ~PollArg(){};

    public:
            /**
                Id of the asynchronous job. This is the value of a response
                returned from the method that launched the job.
            */
        QString asyncJobId()const{return m_async_job_id;};
        PollArg& setAsyncjobid(const QString& arg){m_async_job_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PollArg>  create(const QByteArray& data);
            static std::unique_ptr<PollArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Id of the asynchronous job. This is the value of a response
                returned from the method that launched the job.
            */
        QString m_async_job_id;

    };//PollArg

}//async
}//dropboxQt
