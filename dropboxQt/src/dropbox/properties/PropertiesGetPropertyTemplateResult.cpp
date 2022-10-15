/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "properties"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/properties/PropertiesGetPropertyTemplateResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace properties{
///GetPropertyTemplateResult

GetPropertyTemplateResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetPropertyTemplateResult::toJson(QJsonObject& js)const{

    PropertyGroupTemplate::toJson(js);
}

void GetPropertyTemplateResult::fromJson(const QJsonObject& js){

    PropertyGroupTemplate::fromJson(js);
}

QString GetPropertyTemplateResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetPropertyTemplateResult>  GetPropertyTemplateResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetPropertyTemplateResult>  GetPropertyTemplateResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetPropertyTemplateResult> rv;
    rv = std::unique_ptr<GetPropertyTemplateResult>(new GetPropertyTemplateResult);
    rv->fromJson(js);
    return rv;
}

}//properties
}//dropboxQt
