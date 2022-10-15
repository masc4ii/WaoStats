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
    class PollResultBase{
        /**
            Result returned by methods that poll for the status of an
            asynchronous job. Unions that extend this union should add a
            'complete' field with a type of the information returned upon job
            completion. See :class:`PollEmptyResult` for an example.

            field: in_progress: The asynchronous job is still in progress.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS
        };

        PollResultBase(){}
        PollResultBase(Tag v):m_tag(v){}
        virtual ~PollResultBase(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PollResultBase>  create(const QByteArray& data);
            static std::unique_ptr<PollResultBase>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//PollResultBase

}//async
}//dropboxQt
