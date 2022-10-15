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
    class ListPropertyTemplateIds{
        /**
            field: template_ids: List of identifiers for templates added by
                route properties/template/add.
        */

    public:
        ListPropertyTemplateIds(){};

        ListPropertyTemplateIds(const std::list <QString>& arg){ m_template_ids = arg; };
        virtual ~ListPropertyTemplateIds(){};

    public:
            /**
                List of identifiers for templates added by route
                properties/template/add.
            */
        const std::list <QString>& templateIds()const{return m_template_ids;};
        ListPropertyTemplateIds& setTemplateids(const std::list <QString>& arg){m_template_ids=arg;return *this;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<ListPropertyTemplateIds>  create(const QByteArray& data);
            static std::unique_ptr<ListPropertyTemplateIds>  create(const QJsonObject& js);
        };



    protected:
            /**
                List of identifiers for templates added by route
                properties/template/add.
            */
        std::list <QString> m_template_ids;

    };//ListPropertyTemplateIds

}//properties
}//dropboxQt
