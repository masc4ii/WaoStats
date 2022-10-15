/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesPropertyFieldTemplate.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace properties{
///PropertyFieldTemplate

PropertyFieldTemplate::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PropertyFieldTemplate::toJson(QJsonObject& js)const{

    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(!m_description.isEmpty())
        js["description"] = QString(m_description);
    m_type.toJson(js, "type");
}

void PropertyFieldTemplate::fromJson(const QJsonObject& js){

    m_name = js["name"].toString();
    m_description = js["description"].toString();
    m_type.fromJson(js["type"].toObject());
}

QString PropertyFieldTemplate::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PropertyFieldTemplate>  PropertyFieldTemplate::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PropertyFieldTemplate>  PropertyFieldTemplate::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PropertyFieldTemplate> rv;
    rv = std::unique_ptr<PropertyFieldTemplate>(new PropertyFieldTemplate);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
