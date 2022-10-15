/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesGetMetadataError.h"
#include "dropbox/files/FilesLookUpPropertiesError.h"

namespace dropboxQt{
namespace files{
    class AlphaGetMetadataError{
    public:
        enum Tag{

        /*None*/
        GetMetadataError_PATH,
        /*None*/
        AlphaGetMetadataError_PROPERTIES_ERROR
        };

        AlphaGetMetadataError(){}
        AlphaGetMetadataError(Tag v):m_tag(v){}
        virtual ~AlphaGetMetadataError(){}

        Tag tag()const{return m_tag;}
        ///None
        const LookupError& getPath()const{API_CHECK_STATE((GetMetadataError_PATH == m_tag), "expected tag: GetMetadataError_PATH", m_tag);return m_path;};

        ///None
        const LookUpPropertiesError& getPropertiesError()const{API_CHECK_STATE((AlphaGetMetadataError_PROPERTIES_ERROR == m_tag), "expected tag: AlphaGetMetadataError_PROPERTIES_ERROR", m_tag);return m_properties_error;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AlphaGetMetadataError>  create(const QByteArray& data);
            static std::unique_ptr<AlphaGetMetadataError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        LookupError m_path;
        LookUpPropertiesError m_properties_error;
    };//AlphaGetMetadataError

}//files
}//dropboxQt
