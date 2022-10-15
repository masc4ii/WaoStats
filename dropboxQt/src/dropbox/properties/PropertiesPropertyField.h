/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace properties{
    class PropertyField{
        /**
            field: name: This is the name or key of a custom property in a
                property template. File property names can be up to 256 bytes.
            field: value: Value of a custom property attached to a file. Values
                can be up to 1024 bytes.
        */

    public:
        PropertyField(){};

        PropertyField(const QString& arg){ m_name = arg; };
        virtual ~PropertyField(){};

    public:
            /**
                This is the name or key of a custom property in a property
                template. File property names can be up to 256 bytes.
            */
        QString name()const{return m_name;};
        PropertyField& setName(const QString& arg){m_name=arg;return *this;};

            /**
                Value of a custom property attached to a file. Values can be up
                to 1024 bytes.
            */
        QString value()const{return m_value;};
        PropertyField& setValue(const QString& arg){m_value=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PropertyField>  create(const QByteArray& data);
            static std::unique_ptr<PropertyField>  create(const QJsonObject& js);
        };



    protected:
            /**
                This is the name or key of a custom property in a property
                template. File property names can be up to 256 bytes.
            */
        QString m_name;

            /**
                Value of a custom property attached to a file. Values can be up
                to 1024 bytes.
            */
        QString m_value;

    };//PropertyField

}//properties
}//dropboxQt
