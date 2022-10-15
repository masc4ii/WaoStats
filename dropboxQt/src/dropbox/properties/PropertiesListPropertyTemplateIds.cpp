/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesListPropertyTemplateIds.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace properties{
///ListPropertyTemplateIds

ListPropertyTemplateIds::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListPropertyTemplateIds::toJson(QJsonObject& js)const{

    js["template_ids"] = ingrl_list2jsonarray(m_template_ids);
}

void ListPropertyTemplateIds::fromJson(const QJsonObject& js){

    jsonarray2ingrl_list(js["template_ids"].toArray(), m_template_ids);
}

QString ListPropertyTemplateIds::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListPropertyTemplateIds>  ListPropertyTemplateIds::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListPropertyTemplateIds>  ListPropertyTemplateIds::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListPropertyTemplateIds> rv;
    rv = std::unique_ptr<ListPropertyTemplateIds>(new ListPropertyTemplateIds);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
