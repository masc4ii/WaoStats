/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesUploadSessionCursor.h"

namespace dropboxQt{
namespace files{
    class UploadSessionAppendArg{
        /**
            field: cursor: Contains the upload session ID and the offset.
            field: close: If true, the current session will be closed, at which
                point you won't be able to call :meth:`upload_session_append_v2`
                anymore with the current session.
        */

    public:
        UploadSessionAppendArg():
        m_close(false)
        {};

        UploadSessionAppendArg(const UploadSessionCursor& arg):
        m_close(false)
        { m_cursor = arg; };
        virtual ~UploadSessionAppendArg(){};

    public:
            /**
                Contains the upload session ID and the offset.
            */
        const UploadSessionCursor& cursor()const{return m_cursor;};
        UploadSessionAppendArg& setCursor(const UploadSessionCursor& arg){m_cursor=arg;return *this;};

            /**
                If true, the current session will be closed, at which point you
                won't be able to call :meth:`upload_session_append_v2` anymore
                with the current session.
            */
        bool close()const{return m_close;};
        UploadSessionAppendArg& setClose(const bool& arg){m_close=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionAppendArg>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionAppendArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                Contains the upload session ID and the offset.
            */
        UploadSessionCursor m_cursor;

            /**
                If true, the current session will be closed, at which point you
                won't be able to call :meth:`upload_session_append_v2` anymore
                with the current session.
            */
        bool m_close;

    };//UploadSessionAppendArg

}//files
}//dropboxQt
