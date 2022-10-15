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
#include "dropbox/sharing/SharingMemberAccessLevelResult.h"
#include "dropbox/sharing/SharingRemoveFolderMemberError.h"

namespace dropboxQt{
namespace sharing{
    class RemoveMemberJobStatus{
        /**
            field: complete: Removing the folder member has finished. The value
                is information about whether the member has another form of
                access.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS,
        /*Removing the folder member has finished. The value is information about whether the member has another form of access.*/
        RemoveMemberJobStatus_COMPLETE,
        /*None*/
        RemoveMemberJobStatus_FAILED
        };

        RemoveMemberJobStatus(){}
        RemoveMemberJobStatus(Tag v):m_tag(v){}
        virtual ~RemoveMemberJobStatus(){}

        Tag tag()const{return m_tag;}
        ///Removing the folder member has finished. The value is information about whether the member has another form of access.
        const MemberAccessLevelResult& getComplete()const{API_CHECK_STATE((RemoveMemberJobStatus_COMPLETE == m_tag), "expected tag: RemoveMemberJobStatus_COMPLETE", m_tag);return m_complete;};

        ///None
        const RemoveFolderMemberError& getFailed()const{API_CHECK_STATE((RemoveMemberJobStatus_FAILED == m_tag), "expected tag: RemoveMemberJobStatus_FAILED", m_tag);return m_failed;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemoveMemberJobStatus>  create(const QByteArray& data);
            static std::unique_ptr<RemoveMemberJobStatus>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        MemberAccessLevelResult m_complete;
        RemoveFolderMemberError m_failed;
    };//RemoveMemberJobStatus

}//sharing
}//dropboxQt
