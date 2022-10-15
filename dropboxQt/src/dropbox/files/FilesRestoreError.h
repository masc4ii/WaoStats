/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesLookupError.h"
#include "dropbox/files/FilesWriteError.h"

namespace dropboxQt{
namespace files{
    class RestoreError{
        /**
            field: path_lookup: An error occurs when downloading metadata for
                the file.
            field: path_write: An error occurs when trying to restore the file
                to that path.
            field: invalid_revision: The revision is invalid. It may point to a
                different file.
        */
    public:
        enum Tag{

        /*An error occurs when downloading metadata for the file.*/
        RestoreError_PATH_LOOKUP,
        /*An error occurs when trying to restore the file to that path.*/
        RestoreError_PATH_WRITE,
        /*The revision is invalid. It may point to a different file.*/
        RestoreError_INVALID_REVISION,
        /*None*/
        RestoreError_OTHER
        };

        RestoreError(){}
        RestoreError(Tag v):m_tag(v){}
        virtual ~RestoreError(){}

        Tag tag()const{return m_tag;}
        ///An error occurs when downloading metadata for the file.
        const LookupError& getPathLookup()const{API_CHECK_STATE((RestoreError_PATH_LOOKUP == m_tag), "expected tag: RestoreError_PATH_LOOKUP", m_tag);return m_path_lookup;};

        ///An error occurs when trying to restore the file to that path.
        const WriteError& getPathWrite()const{API_CHECK_STATE((RestoreError_PATH_WRITE == m_tag), "expected tag: RestoreError_PATH_WRITE", m_tag);return m_path_write;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RestoreError>  create(const QByteArray& data);
            static std::unique_ptr<RestoreError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path_lookup;
        WriteError m_path_write;
    };//RestoreError

}//files
}//dropboxQt
