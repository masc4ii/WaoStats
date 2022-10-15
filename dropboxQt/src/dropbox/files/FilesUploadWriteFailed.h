/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesWriteError.h"

namespace dropboxQt{
namespace files{
    class UploadWriteFailed{
        /**
            field: reason: The reason why the file couldn't be saved.
            field: upload_session_id: The upload session ID; this may be used to
                retry the commit.
        */

    public:
        UploadWriteFailed(){};

        UploadWriteFailed(const WriteError& arg){ m_reason = arg; };
        virtual ~UploadWriteFailed(){};

    public:
            /**
                The reason why the file couldn't be saved.
            */
        const WriteError& reason()const{return m_reason;};
        UploadWriteFailed& setReason(const WriteError& arg){m_reason=arg;return *this;};

            /**
                The upload session ID; this may be used to retry the commit.
            */
        QString uploadSessionId()const{return m_upload_session_id;};
        UploadWriteFailed& setUploadsessionid(const QString& arg){m_upload_session_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadWriteFailed>  create(const QByteArray& data);
            static std::unique_ptr<UploadWriteFailed>  create(const QJsonObject& js);
        };



    protected:
            /**
                The reason why the file couldn't be saved.
            */
        WriteError m_reason;

            /**
                The upload session ID; this may be used to retry the commit.
            */
        QString m_upload_session_id;

    };//UploadWriteFailed

}//files
}//dropboxQt
