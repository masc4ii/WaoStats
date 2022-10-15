/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesUploadWriteFailed.h"

namespace dropboxQt{
namespace files{
    class UploadError{
        /**
            field: path: Unable to save the uploaded contents to a file.
        */
    public:
        enum Tag{

        /*Unable to save the uploaded contents to a file.*/
        UploadError_PATH,
        /*None*/
        UploadError_OTHER
        };

        UploadError(){}
        UploadError(Tag v):m_tag(v){}
        virtual ~UploadError(){}

        Tag tag()const{return m_tag;}
        ///Unable to save the uploaded contents to a file.
        const UploadWriteFailed& getPath()const{API_CHECK_STATE((UploadError_PATH == m_tag), "expected tag: UploadError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadError>  create(const QByteArray& data);
            static std::unique_ptr<UploadError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        UploadWriteFailed m_path;
    };//UploadError

}//files
}//dropboxQt
