/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace files{
    class RemovePropertiesArg{
        /**
            field: path: A unique identifier for the file.
            field: property_template_ids: A list of identifiers for a property
                template created by route properties/template/add.
        */

    public:
        RemovePropertiesArg(){};

        RemovePropertiesArg(const QString& arg){ m_path = arg; };
        virtual ~RemovePropertiesArg(){};

    public:
            /**
                A unique identifier for the file.
            */
        QString path()const{return m_path;};
        RemovePropertiesArg& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                A list of identifiers for a property template created by route
                properties/template/add.
            */
        const std::list <QString>& propertyTemplateIds()const{return m_property_template_ids;};
        RemovePropertiesArg& setPropertytemplateids(const std::list <QString>& arg){m_property_template_ids=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemovePropertiesArg>  create(const QByteArray& data);
            static std::unique_ptr<RemovePropertiesArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                A unique identifier for the file.
            */
        QString m_path;

            /**
                A list of identifiers for a property template created by route
                properties/template/add.
            */
        std::list <QString> m_property_template_ids;

    };//RemovePropertiesArg

}//files
}//dropboxQt
