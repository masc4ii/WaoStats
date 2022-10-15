/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUpdatePropertiesError.h"

namespace dropboxQt{

namespace files{
///UpdatePropertiesError

UpdatePropertiesError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UpdatePropertiesError::toJson(QJsonObject& js, QString name)const{

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
        case PropertiesError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case InvalidPropertyGroupError_PROPERTY_FIELD_TOO_LARGE:{
            if(!name.isEmpty())
                js[name] = QString("property_field_too_large");
        }break;
        case InvalidPropertyGroupError_DOES_NOT_FIT_TEMPLATE:{
            if(!name.isEmpty())
                js[name] = QString("does_not_fit_template");
        }break;
        case UpdatePropertiesError_PROPERTY_GROUP_LOOKUP:{
            if(!name.isEmpty())
                js[name] = QString("property_group_lookup");
            m_property_group_lookup.toJson(js, "property_group_lookup");
        }break;
    }//switch
}

void UpdatePropertiesError::fromJson(const QJsonObject& js){

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
    if(s.compare("path") == 0){
        m_tag = PropertiesError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    if(s.compare("property_field_too_large") == 0){
        m_tag = InvalidPropertyGroupError_PROPERTY_FIELD_TOO_LARGE;

    }
    else if(s.compare("does_not_fit_template") == 0){
        m_tag = InvalidPropertyGroupError_DOES_NOT_FIT_TEMPLATE;

    }
    if(s.compare("property_group_lookup") == 0){
        m_tag = UpdatePropertiesError_PROPERTY_GROUP_LOOKUP;
        m_property_group_lookup.fromJson(js["property_group_lookup"].toObject());
    }
}

QString UpdatePropertiesError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UpdatePropertiesError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UpdatePropertiesError>  UpdatePropertiesError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UpdatePropertiesError> rv = std::unique_ptr<UpdatePropertiesError>(new UpdatePropertiesError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
