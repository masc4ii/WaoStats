/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesWriteConflictError.h"

namespace dropboxQt{
namespace files{
    class WriteError{
        /**
            field: conflict: Couldn't write to the target path because there was
                something in the way.
            field: no_write_permission: The user doesn't have permissions to
                write to the target location.
            field: insufficient_space: The user doesn't have enough available
                space (bytes) to write more data.
            field: disallowed_name: Dropbox will not save the file or folder
                because of its name.
        */
    public:
        enum Tag{

        /*None*/
        WriteError_MALFORMED_PATH,
        /*Couldn't write to the target path because there was something in the way.*/
        WriteError_CONFLICT,
        /*The user doesn't have permissions to write to the target location.*/
        WriteError_NO_WRITE_PERMISSION,
        /*The user doesn't have enough available space (bytes) to write more data.*/
        WriteError_INSUFFICIENT_SPACE,
        /*Dropbox will not save the file or folder because of its name.*/
        WriteError_DISALLOWED_NAME,
        /*None*/
        WriteError_OTHER
        };

        WriteError(){}
        WriteError(Tag v):m_tag(v){}
        virtual ~WriteError(){}

        Tag tag()const{return m_tag;}
        ///None
        QString getMalformedPath()const{API_CHECK_STATE((WriteError_MALFORMED_PATH == m_tag), "expected tag: WriteError_MALFORMED_PATH", m_tag);return m_malformed_path;};

        ///Couldn't write to the target path because there was something in the way.
        const WriteConflictError& getConflict()const{API_CHECK_STATE((WriteError_CONFLICT == m_tag), "expected tag: WriteError_CONFLICT", m_tag);return m_conflict;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<WriteError>  create(const QByteArray& data);
            static std::unique_ptr<WriteError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_malformed_path;
        WriteConflictError m_conflict;
    };//WriteError

}//files
}//dropboxQt
