/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace files{
    class UploadSessionStartResult{
        /**
            field: session_id: A unique identifier for the upload session. Pass
                this to :meth:`upload_session_append_v2` and
                :meth:`upload_session_finish`.
        */

    public:
        UploadSessionStartResult(){};

        UploadSessionStartResult(const QString& arg){ m_session_id = arg; };
        virtual ~UploadSessionStartResult(){};

    public:
            /**
                A unique identifier for the upload session. Pass this to
                :meth:`upload_session_append_v2` and
                :meth:`upload_session_finish`.
            */
        QString sessionId()const{return m_session_id;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionStartResult>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionStartResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                A unique identifier for the upload session. Pass this to
                :meth:`upload_session_append_v2` and
                :meth:`upload_session_finish`.
            */
        QString m_session_id;

    };//UploadSessionStartResult

}//files
}//dropboxQt
