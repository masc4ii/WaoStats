/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesPropertyGroupTemplate.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace properties{
///PropertyGroupTemplate

PropertyGroupTemplate::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PropertyGroupTemplate::toJson(QJsonObject& js)const{

    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(!m_description.isEmpty())
        js["description"] = QString(m_description);
    js["fields"] = struct_list2jsonarray(m_fields);
}

void PropertyGroupTemplate::fromJson(const QJsonObject& js){

    m_name = js["name"].toString();
    m_description = js["description"].toString();
    jsonarray2struct_list(js["fields"].toArray(), m_fields);
}

QString PropertyGroupTemplate::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PropertyGroupTemplate>  PropertyGroupTemplate::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PropertyGroupTemplate>  PropertyGroupTemplate::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PropertyGroupTemplate> rv;
    rv = std::unique_ptr<PropertyGroupTemplate>(new PropertyGroupTemplate);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
