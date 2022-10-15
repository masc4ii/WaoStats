/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#pragma once

#include "dropbox/endpoint/ApiUtil.h"
#include "dropbox/files/FilesPropertiesError.h"
#include "dropbox/files/FilesLookUpPropertiesError.h"

namespace dropboxQt{
namespace files{
    class RemovePropertiesError{
    public:
        enum Tag{

        /*Property template does not exist for given identifier.*/
        PropertyTemplateError_TEMPLATE_NOT_FOUND,
        /*You do not have the permissions to modify this property template.*/
        PropertyTemplateError_RESTRICTED_CONTENT,
        /*None*/
        PropertyTemplateError_OTHER,
        /*None*/
        PropertiesError_PATH,
        /*None*/
        RemovePropertiesError_PROPERTY_GROUP_LOOKUP
        };

        RemovePropertiesError(){}
        RemovePropertiesError(Tag v):m_tag(v){}
        virtual ~RemovePropertiesError(){}

        Tag tag()const{return m_tag;}
        ///Property template does not exist for given identifier.
        QString getTemplateNotFound()const{API_CHECK_STATE((PropertyTemplateError_TEMPLATE_NOT_FOUND == m_tag), "expected tag: PropertyTemplateError_TEMPLATE_NOT_FOUND", m_tag);return m_template_not_found;};

        ///None
        const LookupError& getPath()const{API_CHECK_STATE((PropertiesError_PATH == m_tag), "expected tag: PropertiesError_PATH", m_tag);return m_path;};

        ///None
        const LookUpPropertiesError& getPropertyGroupLookup()const{API_CHECK_STATE((RemovePropertiesError_PROPERTY_GROUP_LOOKUP == m_tag), "expected tag: RemovePropertiesError_PROPERTY_GROUP_LOOKUP", m_tag);return m_property_group_lookup;};

    public:
        operator QJsonObject ()const;
        virtual void fromJson(const QJsonObject& js);
        virtual void toJson(QJsonObject& js, QString name)const;
        virtual QString toString(bool multiline = true)const;


        class factory{
        public:
            static std::unique_ptr<RemovePropertiesError>  create(const QByteArray& data);
            static std::unique_ptr<RemovePropertiesError>  create(const QJsonObject& js);
        };



    protected:
        Tag m_tag;
        QString m_template_not_found;
        LookupError m_path;
        LookUpPropertiesError m_property_group_lookup;
    };//RemovePropertiesError

}//files
}//dropboxQt
