/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyGroup.h"

namespace dropboxQt{
namespace files{
    class PropertyGroupWithPath{
        /**
            field: path: A unique identifier for the file.
            field: property_groups: Filled custom property templates associated
                with a file.
        */

    public:
        PropertyGroupWithPath(){};

        PropertyGroupWithPath(const QString& arg){ m_path = arg; };
        virtual ~PropertyGroupWithPath(){};

    public:
            /**
                A unique identifier for the file.
            */
        QString path()const{return m_path;};
        PropertyGroupWithPath& setPath(const QString& arg){m_path=arg;return *this;};

            /**
                Filled custom property templates associated with a file.
            */
        const std::list <properties::PropertyGroup>& propertyGroups()const{return m_property_groups;};
        PropertyGroupWithPath& setPropertygroups(const std::list <properties::PropertyGroup>& arg){m_property_groups=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PropertyGroupWithPath>  create(const QByteArray& data);
            static std::unique_ptr<PropertyGroupWithPath>  create(const QJsonObject& js);
        };



    protected:
            /**
                A unique identifier for the file.
            */
        QString m_path;

            /**
                Filled custom property templates associated with a file.
            */
        std::list <properties::PropertyGroup> m_property_groups;

    };//PropertyGroupWithPath

}//files
}//dropboxQt
