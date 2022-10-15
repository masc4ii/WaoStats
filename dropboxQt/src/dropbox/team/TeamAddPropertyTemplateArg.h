/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyGroupTemplate.h"

namespace dropboxQt{
namespace team{
    class AddPropertyTemplateArg : public properties::PropertyGroupTemplate{
        /**
            Arguments for adding property templates.
        */

    public:
        AddPropertyTemplateArg(){};

        virtual ~AddPropertyTemplateArg(){};

    public:
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<AddPropertyTemplateArg>  create(const QByteArray& data);
            static std::unique_ptr<AddPropertyTemplateArg>  create(const QJsonObject& js);
        };



    protected:
    };//AddPropertyTemplateArg

}//team
}//dropboxQt
