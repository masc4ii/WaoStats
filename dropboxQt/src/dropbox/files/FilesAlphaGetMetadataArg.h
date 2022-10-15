/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesGetMetadataArg.h"

namespace dropboxQt{
namespace files{
    class AlphaGetMetadataArg : public GetMetadataArg{
        /**
            field: include_property_templates: If set to a valid list of
                template IDs, ``FileMetadata.property_groups`` is set for files
                with custom properties.
        */

    public:
        AlphaGetMetadataArg(){};

        AlphaGetMetadataArg(const std::list <QString>& arg){ m_include_property_templates = arg; };
        virtual ~AlphaGetMetadataArg(){};

    public:
            /**
                If set to a valid list of template IDs,
                ``FileMetadata.property_groups`` is set for files with custom
                properties.
            */
        const std::list <QString>& includePropertyTemplates()const{return m_include_property_templates;};
        AlphaGetMetadataArg& setIncludepropertytemplates(const std::list <QString>& arg){m_include_property_templates=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AlphaGetMetadataArg>  create(const QByteArray& data);
            static std::unique_ptr<AlphaGetMetadataArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                If set to a valid list of template IDs,
                ``FileMetadata.property_groups`` is set for files with custom
                properties.
            */
        std::list <QString> m_include_property_templates;

    };//AlphaGetMetadataArg

}//files
}//dropboxQt
