/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesModifyPropertyTemplateError.h"

namespace dropboxQt{

namespace properties{
///ModifyPropertyTemplateError

ModifyPropertyTemplateError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ModifyPropertyTemplateError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PropertyTemplateError_TEMPLATE_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("template_not_found");
            if(!m_template_not_found.isEmpty())
                js["template_not_found"] = QString(m_template_not_found);
        }break;
        case PropertyTemplateError_RESTRICTED_CONTENT:{
            if(!name.isEmpty())
                js[name] = QString("restricted_content");
        }break;
        case PropertyTemplateError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case ModifyPropertyTemplateError_CONFLICTING_PROPERTY_NAMES:{
            if(!name.isEmpty())
                js[name] = QString("conflicting_property_names");
        }break;
        case ModifyPropertyTemplateError_TOO_MANY_PROPERTIES:{
            if(!name.isEmpty())
                js[name] = QString("too_many_properties");
        }break;
        case ModifyPropertyTemplateError_TOO_MANY_TEMPLATES:{
            if(!name.isEmpty())
                js[name] = QString("too_many_templates");
        }break;
        case ModifyPropertyTemplateError_TEMPLATE_ATTRIBUTE_TOO_LARGE:{
            if(!name.isEmpty())
                js[name] = QString("template_attribute_too_large");
        }break;
    }//switch
}

void ModifyPropertyTemplateError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("template_not_found") == 0){
        m_tag = PropertyTemplateError_TEMPLATE_NOT_FOUND;
        m_template_not_found = js["template_not_found"].toString();
    }
    else if(s.compare("restricted_content") == 0){
        m_tag = PropertyTemplateError_RESTRICTED_CONTENT;

    }
    else if(s.compare("other") == 0){
        m_tag = PropertyTemplateError_OTHER;

    }
    if(s.compare("conflicting_property_names") == 0){
        m_tag = ModifyPropertyTemplateError_CONFLICTING_PROPERTY_NAMES;

    }
    else if(s.compare("too_many_properties") == 0){
        m_tag = ModifyPropertyTemplateError_TOO_MANY_PROPERTIES;

    }
    else if(s.compare("too_many_templates") == 0){
        m_tag = ModifyPropertyTemplateError_TOO_MANY_TEMPLATES;

    }
    else if(s.compare("template_attribute_too_large") == 0){
        m_tag = ModifyPropertyTemplateError_TEMPLATE_ATTRIBUTE_TOO_LARGE;

    }
}

QString ModifyPropertyTemplateError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ModifyPropertyTemplateError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ModifyPropertyTemplateError>  ModifyPropertyTemplateError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ModifyPropertyTemplateError> rv = std::unique_ptr<ModifyPropertyTemplateError>(new ModifyPropertyTemplateError);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
