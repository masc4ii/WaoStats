/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesUploadSessionOffsetError.h"

namespace dropboxQt{
namespace files{
    class UploadSessionLookupError{
        /**
            field: not_found: The upload session id was not found.
            field: incorrect_offset: The specified offset was incorrect. See the
                value for the correct offset. (This error may occur when a
                previous request was received and processed successfully but the
                client did not receive the response, e.g. due to a network
                error.)
            field: closed: You are attempting to append data to an upload
                session that has alread been closed (i.e. committed).
            field: not_closed: The session must be closed before calling
                upload_session/finish_batch.
        */
    public:
        enum Tag{

        /*The upload session id was not found.*/
        UploadSessionLookupError_NOT_FOUND,
        /*The specified offset was incorrect. See the value for the correct offset. (This error may occur when a previous request was received and processed successfully but the client did not receive the response, e.g. due to a network error.)*/
        UploadSessionLookupError_INCORRECT_OFFSET,
        /*You are attempting to append data to an upload session that has alread been closed (i.e. committed).*/
        UploadSessionLookupError_CLOSED,
        /*The session must be closed before calling upload_session/finish_batch.*/
        UploadSessionLookupError_NOT_CLOSED,
        /*None*/
        UploadSessionLookupError_OTHER
        };

        UploadSessionLookupError(){}
        UploadSessionLookupError(Tag v):m_tag(v){}
        virtual ~UploadSessionLookupError(){}

        Tag tag()const{return m_tag;}
        ///The specified offset was incorrect. See the value for the correct offset. (This error may occur when a previous request was received and processed successfully but the client did not receive the response, e.g. due to a network error.)
        const UploadSessionOffsetError& getIncorrectOffset()const{API_CHECK_STATE((UploadSessionLookupError_INCORRECT_OFFSET == m_tag), "expected tag: UploadSessionLookupError_INCORRECT_OFFSET", m_tag);return m_incorrect_offset;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadSessionLookupError>  create(const QByteArray& data);
            static std::unique_ptr<UploadSessionLookupError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        UploadSessionOffsetError m_incorrect_offset;
    };//UploadSessionLookupError

}//files
}//dropboxQt
