/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyFieldTemplate.h"

namespace dropboxQt{
namespace team{
    class UpdatePropertyTemplateArg{
        /**
            field: template_id: An identifier for property template added by
                :meth:`properties_template_add`.
            field: name: A display name for the property template. Property
                template names can be up to 256 bytes.
            field: description: Description for new property template. Property
                template descriptions can be up to 1024 bytes.
            field: add_fields: This is a list of custom properties to add to the
                property template. There can be up to 64 properties in a single
                property template.
        */

    public:
        UpdatePropertyTemplateArg(){};

        UpdatePropertyTemplateArg(const QString& arg){ m_template_id = arg; };
        virtual ~UpdatePropertyTemplateArg(){};

    public:
            /**
                An identifier for property template added by
                :meth:`properties_template_add`.
            */
        QString templateId()const{return m_template_id;};
        UpdatePropertyTemplateArg& setTemplateid(const QString& arg){m_template_id=arg;return *this;};

            /**
                A display name for the property template. Property template
                names can be up to 256 bytes.
            */
        QString name()const{return m_name;};
        UpdatePropertyTemplateArg& setName(const QString& arg){m_name=arg;return *this;};

            /**
                Description for new property template. Property template
                descriptions can be up to 1024 bytes.
            */
        QString description()const{return m_description;};
        UpdatePropertyTemplateArg& setDescription(const QString& arg){m_description=arg;return *this;};

            /**
                This is a list of custom properties to add to the property
                template. There can be up to 64 properties in a single property
                template.
            */
        const std::list <properties::PropertyFieldTemplate>& addFields()const{return m_add_fields;};
        UpdatePropertyTemplateArg& setAddfields(const std::list <properties::PropertyFieldTemplate>& arg){m_add_fields=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UpdatePropertyTemplateArg>  create(const QByteArray& data);
            static std::unique_ptr<UpdatePropertyTemplateArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                An identifier for property template added by
                :meth:`properties_template_add`.
            */
        QString m_template_id;

            /**
                A display name for the property template. Property template
                names can be up to 256 bytes.
            */
        QString m_name;

            /**
                Description for new property template. Property template
                descriptions can be up to 1024 bytes.
            */
        QString m_description;

            /**
                This is a list of custom properties to add to the property
                template. There can be up to 64 properties in a single property
                template.
            */
        std::list <properties::PropertyFieldTemplate> m_add_fields;

    };//UpdatePropertyTemplateArg

}//team
}//dropboxQt
