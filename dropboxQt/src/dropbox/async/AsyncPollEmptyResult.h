/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/async/AsyncPollResultBase.h"

namespace dropboxQt{
namespace async{
    class PollEmptyResult{
        /**
            Result returned by methods that poll for the status of an
            asynchronous job. Upon completion of the job, no additional
            information is returned.

            field: complete: The asynchronous job has completed successfully.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS,
        /*The asynchronous job has completed successfully.*/
        PollEmptyResult_COMPLETE
        };

        PollEmptyResult(){}
        PollEmptyResult(Tag v):m_tag(v){}
        virtual ~PollEmptyResult(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PollEmptyResult>  create(const QByteArray& data);
            static std::unique_ptr<PollEmptyResult>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//PollEmptyResult

}//async
}//dropboxQt
