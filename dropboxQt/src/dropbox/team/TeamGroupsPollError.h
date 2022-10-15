/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/async/AsyncPollError.h"

namespace dropboxQt{
namespace team{
    class GroupsPollError{
        /**
            field: access_denied: You are not allowed to poll this job.
        */
    public:
        enum Tag{

        /*The job ID is invalid.*/
        PollError_INVALID_ASYNC_JOB_ID,
        /*Something went wrong with the job on Dropbox's end. You'll need to verify that the action you were taking succeeded, and if not, try again. This should happen very rarely.*/
        PollError_INTERNAL_ERROR,
        /*None*/
        PollError_OTHER,
        /*You are not allowed to poll this job.*/
        GroupsPollError_ACCESS_DENIED
        };

        GroupsPollError(){}
        GroupsPollError(Tag v):m_tag(v){}
        virtual ~GroupsPollError(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GroupsPollError>  create(const QByteArray& data);
            static std::unique_ptr<GroupsPollError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//GroupsPollError

}//team
}//dropboxQt
