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
#include "dropbox/sharing/SharingSharedFolderMetadata.h"
#include "dropbox/sharing/SharingShareFolderError.h"

namespace dropboxQt{
namespace sharing{
    class ShareFolderJobStatus{
        /**
            field: complete: The share job has finished. The value is the
                metadata for the folder.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS,
        /*The share job has finished. The value is the metadata for the folder.*/
        ShareFolderJobStatus_COMPLETE,
        /*None*/
        ShareFolderJobStatus_FAILED
        };

        ShareFolderJobStatus(){}
        ShareFolderJobStatus(Tag v):m_tag(v){}
        virtual ~ShareFolderJobStatus(){}

        Tag tag()const{return m_tag;}
        ///The share job has finished. The value is the metadata for the folder.
        const SharedFolderMetadata& getComplete()const{API_CHECK_STATE((ShareFolderJobStatus_COMPLETE == m_tag), "expected tag: ShareFolderJobStatus_COMPLETE", m_tag);return m_complete;};

        ///None
        const ShareFolderError& getFailed()const{API_CHECK_STATE((ShareFolderJobStatus_FAILED == m_tag), "expected tag: ShareFolderJobStatus_FAILED", m_tag);return m_failed;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ShareFolderJobStatus>  create(const QByteArray& data);
            static std::unique_ptr<ShareFolderJobStatus>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        SharedFolderMetadata m_complete;
        ShareFolderError m_failed;
    };//ShareFolderJobStatus

}//sharing
}//dropboxQt
