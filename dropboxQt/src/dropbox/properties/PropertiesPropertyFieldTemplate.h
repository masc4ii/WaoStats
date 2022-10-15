/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyType.h"

namespace dropboxQt{
namespace properties{
    class PropertyFieldTemplate{
        /**
            Describe a single property field type which that can be part of a
            property template.

            field: name: This is the name or key of a custom property in a
                property template. File property names can be up to 256 bytes.
            field: description: This is the description for a custom property in
                a property template. File property description can be up to 1024
                bytes.
            field: type: This is the data type of the value of this property.
                This type will be enforced upon property creation and
                modifications.
        */

    public:
        PropertyFieldTemplate(){};

        PropertyFieldTemplate(const QString& arg){ m_name = arg; };
        virtual ~PropertyFieldTemplate(){};

    public:
            /**
                This is the name or key of a custom property in a property
                template. File property names can be up to 256 bytes.
            */
        QString name()const{return m_name;};
        PropertyFieldTemplate& setName(const QString& arg){m_name=arg;return *this;};

            /**
                This is the description for a custom property in a property
                template. File property description can be up to 1024 bytes.
            */
        QString description()const{return m_description;};
        PropertyFieldTemplate& setDescription(const QString& arg){m_description=arg;return *this;};

            /**
                This is the data type of the value of this property. This type
                will be enforced upon property creation and modifications.
            */
        const PropertyType& type()const{return m_type;};
        PropertyFieldTemplate& setType(const PropertyType& arg){m_type=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PropertyFieldTemplate>  create(const QByteArray& data);
            static std::unique_ptr<PropertyFieldTemplate>  create(const QJsonObject& js);
        };



    protected:
            /**
                This is the name or key of a custom property in a property
                template. File property names can be up to 256 bytes.
            */
        QString m_name;

            /**
                This is the description for a custom property in a property
                template. File property description can be up to 1024 bytes.
            */
        QString m_description;

            /**
                This is the data type of the value of this property. This type
                will be enforced upon property creation and modifications.
            */
        PropertyType m_type;

    };//PropertyFieldTemplate

}//properties
}//dropboxQt
