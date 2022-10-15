/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesGetPropertyTemplateArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace properties{
///GetPropertyTemplateArg

GetPropertyTemplateArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetPropertyTemplateArg::toJson(QJsonObject& js)const{

    if(!m_template_id.isEmpty())
        js["template_id"] = QString(m_template_id);
}

void GetPropertyTemplateArg::fromJson(const QJsonObject& js){

    m_template_id = js["template_id"].toString();
}

QString GetPropertyTemplateArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetPropertyTemplateArg>  GetPropertyTemplateArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetPropertyTemplateArg>  GetPropertyTemplateArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetPropertyTemplateArg> rv;
    rv = std::unique_ptr<GetPropertyTemplateArg>(new GetPropertyTemplateArg);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
