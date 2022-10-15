/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesUploadError.h"
#include "dropbox/files/FilesInvalidPropertyGroupError.h"

namespace dropboxQt{
namespace files{
    class UploadErrorWithProperties{
    public:
        enum Tag{

        /*Unable to save the uploaded contents to a file.*/
        UploadError_PATH,
        /*None*/
        UploadError_OTHER,
        /*None*/
        UploadErrorWithProperties_PROPERTIES_ERROR
        };

        UploadErrorWithProperties(){}
        UploadErrorWithProperties(Tag v):m_tag(v){}
        virtual ~UploadErrorWithProperties(){}

        Tag tag()const{return m_tag;}
        ///Unable to save the uploaded contents to a file.
        const UploadWriteFailed& getPath()const{API_CHECK_STATE((UploadError_PATH == m_tag), "expected tag: UploadError_PATH", m_tag);return m_path;};

        ///None
        const InvalidPropertyGroupError& getPropertiesError()const{API_CHECK_STATE((UploadErrorWithProperties_PROPERTIES_ERROR == m_tag), "expected tag: UploadErrorWithProperties_PROPERTIES_ERROR", m_tag);return m_properties_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UploadErrorWithProperties>  create(const QByteArray& data);
            static std::unique_ptr<UploadErrorWithProperties>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        UploadWriteFailed m_path;
        InvalidPropertyGroupError m_properties_error;
    };//UploadErrorWithProperties

}//files
}//dropboxQt
