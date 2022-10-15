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
    class DeleteError{
    public:
        enum Tag{

        /*None*/
        DeleteError_PATH_LOOKUP,
        /*None*/
        DeleteError_PATH_WRITE,
        /*None*/
        DeleteError_OTHER
        };

        DeleteError(){}
        DeleteError(Tag v):m_tag(v){}
        virtual ~DeleteError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPathLookup()const{API_CHECK_STATE((DeleteError_PATH_LOOKUP == m_tag), "expected tag: DeleteError_PATH_LOOKUP", m_tag);return m_path_lookup;};

        ///None
        const WriteError& getPathWrite()const{API_CHECK_STATE((DeleteError_PATH_WRITE == m_tag), "expected tag: DeleteError_PATH_WRITE", m_tag);return m_path_write;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<DeleteError>  create(const QByteArray& data);
            static std::unique_ptr<DeleteError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path_lookup;
        WriteError m_path_write;
    };//DeleteError

}//files
}//dropboxQt
