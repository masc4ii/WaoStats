/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesInvalidPropertyGroupError.h"

namespace dropboxQt{
namespace files{
    class AddPropertiesError{
        /**
            field: property_group_already_exists: This property group already
                exists for this file.
        */
    public:
        enum Tag{

        /*Property template does not exist for given identifier.*/
        PropertyTemplateError_TEMPLATE_NOT_FOUND,
        /*You do not have the permissions to modify this property template.*/
        PropertyTemplateError_RESTRICTED_CONTENT,
        /*None*/
        PropertyTemplateError_OTHER,
        /*None*/
        PropertiesError_PATH,
        /*A field value in this property group is too large.*/
        InvalidPropertyGroupError_PROPERTY_FIELD_TOO_LARGE,
        /*The property group specified does not conform to the property template.*/
        InvalidPropertyGroupError_DOES_NOT_FIT_TEMPLATE,
        /*This property group already exists for this file.*/
        AddPropertiesError_PROPERTY_GROUP_ALREADY_EXISTS
        };

        AddPropertiesError(){}
        AddPropertiesError(Tag v):m_tag(v){}
        virtual ~AddPropertiesError(){}

        Tag tag()const{return m_tag;}
        ///Property template does not exist for given identifier.
        QString getTemplateNotFound()const{API_CHECK_STATE((PropertyTemplateError_TEMPLATE_NOT_FOUND == m_tag), "expected tag: PropertyTemplateError_TEMPLATE_NOT_FOUND", m_tag);return m_template_not_found;};

        ///None
        const LookupError& getPath()const{API_CHECK_STATE((PropertiesError_PATH == m_tag), "expected tag: PropertiesError_PATH", m_tag);return m_path;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AddPropertiesError>  create(const QByteArray& data);
            static std::unique_ptr<AddPropertiesError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_template_not_found;
        LookupError m_path;
    };//AddPropertiesError

}//files
}//dropboxQt
