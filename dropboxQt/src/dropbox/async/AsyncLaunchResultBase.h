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
    class LaunchResultBase{
        /**
            Result returned by methods that launch an asynchronous job. A method
            who may either launch an asynchronous job, or complete the request
            synchronously, can use this union by extending it, and adding a
            'complete' field with the type of the synchronous response. See
            :class:`LaunchEmptyResult` for an example.

            field: async_job_id: This response indicates that the processing is
                asynchronous. The string is an id that can be used to obtain the
                status of the asynchronous job.
        */
    public:
        enum Tag{

        /*This response indicates that the processing is asynchronous. The string is an id that can be used to obtain the status of the asynchronous job.*/
        LaunchResultBase_ASYNC_JOB_ID
        };

        LaunchResultBase(){}
        LaunchResultBase(Tag v):m_tag(v){}
        virtual ~LaunchResultBase(){}

        Tag tag()const{return m_tag;}
        ///This response indicates that the processing is asynchronous. The string is an id that can be used to obtain the status of the asynchronous job.
        QString getAsyncJobId()const{API_CHECK_STATE((LaunchResultBase_ASYNC_JOB_ID == m_tag), "expected tag: LaunchResultBase_ASYNC_JOB_ID", m_tag);return m_async_job_id;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<LaunchResultBase>  create(const QByteArray& data);
            static std::unique_ptr<LaunchResultBase>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_async_job_id;
    };//LaunchResultBase

}//async
}//dropboxQt
