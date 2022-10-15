/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/async/AsyncPollResultBase.h"
#include "dropbox/files/FilesFileMetadata.h"
#include "dropbox/files/FilesSaveUrlError.h"

namespace dropboxQt{
namespace files{
    class SaveUrlJobStatus{
        /**
            field: complete: Metadata of the file where the URL is saved to.
        */
    public:
        enum Tag{

        /*The asynchronous job is still in progress.*/
        PollResultBase_IN_PROGRESS,
        /*Metadata of the file where the URL is saved to.*/
        SaveUrlJobStatus_COMPLETE,
        /*None*/
        SaveUrlJobStatus_FAILED
        };

        SaveUrlJobStatus(){}
        SaveUrlJobStatus(Tag v):m_tag(v){}
        virtual ~SaveUrlJobStatus(){}

        Tag tag()const{return m_tag;}
        ///Metadata of the file where the URL is saved to.
        const FileMetadata& getComplete()const{API_CHECK_STATE((SaveUrlJobStatus_COMPLETE == m_tag), "expected tag: SaveUrlJobStatus_COMPLETE", m_tag);return m_complete;};

        ///None
        const SaveUrlError& getFailed()const{API_CHECK_STATE((SaveUrlJobStatus_FAILED == m_tag), "expected tag: SaveUrlJobStatus_FAILED", m_tag);return m_failed;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<SaveUrlJobStatus>  create(const QByteArray& data);
            static std::unique_ptr<SaveUrlJobStatus>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        FileMetadata m_complete;
        SaveUrlError m_failed;
    };//SaveUrlJobStatus

}//files
}//dropboxQt
