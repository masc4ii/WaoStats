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
    class PropertyType{
        /**
            Data type of the given property added. This endpoint is in beta and
            only properties of type strings is supported.

            field: string: The associated property will be of type string.
                Unicode is supported.
        */
    public:
        enum Tag{

        /*The associated property will be of type string. Unicode is supported.*/
        PropertyType_STRING,
        /*None*/
        PropertyType_OTHER
        };

        PropertyType(){}
        PropertyType(Tag v):m_tag(v){}
        virtual ~PropertyType(){}

        Tag tag()const{return m_tag;}
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<PropertyType>  create(const QByteArray& data);
            static std::unique_ptr<PropertyType>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
    };//PropertyType

}//properties
}//dropboxQt
