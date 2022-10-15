/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/async/AsyncLaunchResultBase.h"
#include "dropbox/team/TeamMemberAddResult.h"

namespace dropboxQt{
namespace team{
    class MembersAddLaunch{
    public:
        enum Tag{

        /*This response indicates that the processing is asynchronous. The string is an id that can be used to obtain the status of the asynchronous job.*/
        LaunchResultBase_ASYNC_JOB_ID,
        /*None*/
        MembersAddLaunch_COMPLETE
        };

        MembersAddLaunch(){}
        MembersAddLaunch(Tag v):m_tag(v){}
        virtual ~MembersAddLaunch(){}

        Tag tag()const{return m_tag;}
        ///This response indicates that the processing is asynchronous. The string is an id that can be used to obtain the status of the asynchronous job.
        QString getAsyncJobId()const{API_CHECK_STATE((LaunchResultBase_ASYNC_JOB_ID == m_tag), "expected tag: LaunchResultBase_ASYNC_JOB_ID", m_tag);return m_async_job_id;};

        ///None
        const std::list <MemberAddResult>& getComplete()const{API_CHECK_STATE((MembersAddLaunch_COMPLETE == m_tag), "expected tag: MembersAddLaunch_COMPLETE", m_tag);return m_complete;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<MembersAddLaunch>  create(const QByteArray& data);
            static std::unique_ptr<MembersAddLaunch>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_async_job_id;
        std::list <MemberAddResult> m_complete;
    };//MembersAddLaunch

}//team
}//dropboxQt
