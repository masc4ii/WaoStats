/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyTemplateError.h"

namespace dropboxQt{
namespace properties{
    class ModifyPropertyTemplateError{
        /**
            field: conflicting_property_names: A property field name already
                exists in the template.
            field: too_many_properties: There are too many properties in the
                changed template. The maximum number of properties per template
                is 32.
            field: too_many_templates: There are too many templates for the
                team.
            field: template_attribute_too_large: The template name, description
                or field names is too large.
        */
    public:
        enum Tag{

        /*Property template does not exist for given identifier.*/
        PropertyTemplateError_TEMPLATE_NOT_FOUND,
        /*You do not have the permissions to modify this property template.*/
        PropertyTemplateError_RESTRICTED_CONTENT,
        /*None*/
        PropertyTemplateError_OTHER,
        /*A property field name already exists in the template.*/
        ModifyPropertyTemplateError_CONFLICTING_PROPERTY_NAMES,
        /*There are too many properties in the changed template. The maximum number of properties per template is 32.*/
        ModifyPropertyTemplateError_TOO_MANY_PROPERTIES,
        /*There are too many templates for the team.*/
        ModifyPropertyTemplateError_TOO_MANY_TEMPLATES,
        /*The template name, description or field names is too large.*/
        ModifyPropertyTemplateError_TEMPLATE_ATTRIBUTE_TOO_LARGE
        };

        ModifyPropertyTemplateError(){}
        ModifyPropertyTemplateError(Tag v):m_tag(v){}
        virtual ~ModifyPropertyTemplateError(){}

        Tag tag()const{return m_tag;}
        ///Property template does not exist for given identifier.
        QString getTemplateNotFound()const{API_CHECK_STATE((PropertyTemplateError_TEMPLATE_NOT_FOUND == m_tag), "expected tag: PropertyTemplateError_TEMPLATE_NOT_FOUND", m_tag);return m_template_not_found;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ModifyPropertyTemplateError>  create(const QByteArray& data);
            static std::unique_ptr<ModifyPropertyTemplateError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_template_not_found;
    };//ModifyPropertyTemplateError

}//properties
}//dropboxQt
