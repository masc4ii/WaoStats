/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/properties/PropertiesPropertyGroupTemplate.h"

namespace dropboxQt{
namespace properties{
    class GetPropertyTemplateResult : public PropertyGroupTemplate{
        /**
            The Property template for the specified template.
        */

    public:
        GetPropertyTemplateResult(){};

        virtual ~GetPropertyTemplateResult(){};

    public:
    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetPropertyTemplateResult>  create(const QByteArray& data);
            static std::unique_ptr<GetPropertyTemplateResult>  create(const QJsonObject& js);
        };



    protected:
    };//GetPropertyTemplateResult

}//properties
}//dropboxQt
