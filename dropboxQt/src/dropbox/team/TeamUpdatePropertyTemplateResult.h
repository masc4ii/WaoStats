/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once
#include "dropbox/endpoint/ApiUtil.h"

namespace dropboxQt{
namespace team{
    class UpdatePropertyTemplateResult{
        /**
            field: template_id: An identifier for property template added by
                :meth:`properties_template_add`.
        */

    public:
        UpdatePropertyTemplateResult(){};

        UpdatePropertyTemplateResult(const QString& arg){ m_template_id = arg; };
        virtual ~UpdatePropertyTemplateResult(){};

    public:
            /**
                An identifier for property template added by
                :meth:`properties_template_add`.
            */
        QString templateId()const{return m_template_id;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<UpdatePropertyTemplateResult>  create(const QByteArray& data);
            static std::unique_ptr<UpdatePropertyTemplateResult>  create(const QJsonObject& js);
        };



    protected:
            /**
                An identifier for property template added by
                :meth:`properties_template_add`.
            */
        QString m_template_id;

    };//UpdatePropertyTemplateResult

}//team
}//dropboxQt
