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
    class UploadSessionCursor{
        /**
            field: session_id: The upload session ID (returned by
                :meth:`upload_session_start`).
            field: offset: The amount of data that has been uploaded so far. We
                use this to make sure upload data isn't lost or duplicated in
                the event of a network error.
        */

    public:
        UploadSessionCursor(){};

        UploadSessionCursor(const QString& arg){ m_session_id = arg; };
        virtual ~UploadSessionCursor(){};

    public:
            /**
                The upload session ID (returned by
                :meth:`upload_session_start`).
            */
        QString sessionId()const{return m_session_id;};
        UploadSessionCursor& setSessionid(const QString& arg){m_session_id=arg;return *this;};

            /**
                The amount of data that has been uploaded so far. We use this to
                make sure upload data isn't lost or duplicated in the event of a
                network error.
            */
        int offset()const{return m_offset;};
        UploadSessionCursor& setOffset(const int& arg){m_offset=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionCursor>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionCursor>  create(const QJsonObject& js);
        };



    protected:
            /**
                The upload session ID (returned by
                :meth:`upload_session_start`).
            */
        QString m_session_id;

            /**
                The amount of data that has been uploaded so far. We use this to
                make sure upload data isn't lost or duplicated in the event of a
                network error.
            */
        int m_offset = {0};

    };//UploadSessionCursor

}//files
}//dropboxQt
