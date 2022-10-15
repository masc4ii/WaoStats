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
    class GetPropertyTemplateArg{
        /**
            field: template_id: An identifier for property template added by
                route properties/template/add.
        */

    public:
        GetPropertyTemplateArg(){};

        GetPropertyTemplateArg(const QString& arg){ m_template_id = arg; };
        virtual ~GetPropertyTemplateArg(){};

    public:
            /**
                An identifier for property template added by route
                properties/template/add.
            */
        QString templateId()const{return m_template_id;};
        GetPropertyTemplateArg& setTemplateid(const QString& arg){m_template_id=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<GetPropertyTemplateArg>  create(const QByteArray& data);
            static std::unique_ptr<GetPropertyTemplateArg>  create(const QJsonObject& js);
        };



    protected:
            /**
                An identifier for property template added by route
                properties/template/add.
            */
        QString m_template_id;

    };//GetPropertyTemplateArg

}//properties
}//dropboxQt
