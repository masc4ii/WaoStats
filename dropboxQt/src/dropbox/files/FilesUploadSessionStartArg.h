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
    class UploadSessionStartArg{
        /**
            field: close: If true, the current session will be closed, at which
                point you won't be able to call :meth:`upload_session_append_v2`
                anymore with the current session.
        */

    public:
        UploadSessionStartArg():
        m_close(false)
        {};

        UploadSessionStartArg(const bool& arg):
        m_close(false)
        { m_close = arg; };
        virtual ~UploadSessionStartArg(){};

    public:
            /**
                If true, the current session will be closed, at which point you
                won't be able to call :meth:`upload_session_append_v2` anymore
                with the current session.
            */
        bool close()const{return m_close;};
        UploadSessionStartArg& setClose(const bool& arg){m_close=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionStartArg>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionStartArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                If true, the current session will be closed, at which point you
                won't be able to call :meth:`upload_session_append_v2` anymore
                with the current session.
            */
        bool m_close;

    };//UploadSessionStartArg

}//files
}//dropboxQt
