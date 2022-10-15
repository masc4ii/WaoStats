/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyFieldTemplate.h"

namespace dropboxQt{
namespace properties{
    class PropertyGroupTemplate{
        /**
            Describes property templates that can be filled and associated with
            a file.

            field: name: A display name for the property template. Property
                template names can be up to 256 bytes.
            field: description: Description for new property template. Property
                template descriptions can be up to 1024 bytes.
            field: fields: This is a list of custom properties associated with a
                property template. There can be up to 64 properties in a single
                property template.
        */

    public:
        PropertyGroupTemplate(){};

        PropertyGroupTemplate(const QString& arg){ m_name = arg; };
        virtual ~PropertyGroupTemplate(){};

    public:
            /**
                A display name for the property template. Property template
                names can be up to 256 bytes.
            */
        QString name()const{return m_name;};
        PropertyGroupTemplate& setName(const QString& arg){m_name=arg;return *this;};

            /**
                Description for new property template. Property template
                descriptions can be up to 1024 bytes.
            */
        QString description()const{return m_description;};
        PropertyGroupTemplate& setDescription(const QString& arg){m_description=arg;return *this;};

            /**
                This is a list of custom properties associated with a property
                template. There can be up to 64 properties in a single property
                template.
            */
        const std::list <PropertyFieldTemplate>& fields()const{return m_fields;};
        PropertyGroupTemplate& setFields(const std::list <PropertyFieldTemplate>& arg){m_fields=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PropertyGroupTemplate>  create(const QByteArray& data);
            static std::unique_ptr<PropertyGroupTemplate>  create(const QJsonObject& js);
        };



    protected:
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
                This is a list of custom properties associated with a property
                template. There can be up to 64 properties in a single property
                template.
            */
        std::list <PropertyFieldTemplate> m_fields;

    };//PropertyGroupTemplate

}//properties
}//dropboxQt
