/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyField.h"

namespace dropboxQt{
namespace files{
    class PropertyGroupUpdate{
        /**
            field: template_id: A unique identifier for a property template.
            field: add_or_update_fields: List of property fields to update if
                the field already exists. If the field doesn't exist, add the
                field to the property group.
            field: remove_fields: List of property field names to remove from
                property group if the field exists.
        */

    public:
        PropertyGroupUpdate(){};

        PropertyGroupUpdate(const QString& arg){ m_template_id = arg; };
        virtual ~PropertyGroupUpdate(){};

    public:
            /**
                A unique identifier for a property template.
            */
        QString templateId()const{return m_template_id;};
        PropertyGroupUpdate& setTemplateid(const QString& arg){m_template_id=arg;return *this;};

            /**
                List of property fields to update if the field already exists.
                If the field doesn't exist, add the field to the property group.
            */
        const std::list <properties::PropertyField>& addOrUpdateFields()const{return m_add_or_update_fields;};
        PropertyGroupUpdate& setAddorupdatefields(const std::list <properties::PropertyField>& arg){m_add_or_update_fields=arg;return *this;};

            /**
                List of property field names to remove from property group if
                the field exists.
            */
        const std::list <QString>& removeFields()const{return m_remove_fields;};
        PropertyGroupUpdate& setRemovefields(const std::list <QString>& arg){m_remove_fields=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PropertyGroupUpdate>  create(const QByteArray& data);
            static std::unique_ptr<PropertyGroupUpdate>  create(const QJsonObject& js);
        };



    protected:
            /**
                A unique identifier for a property template.
            */
        QString m_template_id;

            /**
                List of property fields to update if the field already exists.
                If the field doesn't exist, add the field to the property group.
            */
        std::list <properties::PropertyField> m_add_or_update_fields;

            /**
                List of property field names to remove from property group if
                the field exists.
            */
        std::list <QString> m_remove_fields;

    };//PropertyGroupUpdate

}//files
}//dropboxQt
