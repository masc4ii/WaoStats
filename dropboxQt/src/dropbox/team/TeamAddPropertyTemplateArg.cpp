/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamAddPropertyTemplateArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///AddPropertyTemplateArg

AddPropertyTemplateArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void AddPropertyTemplateArg::toJson(QJsonObject& js)const{

    PropertyGroupTemplate::toJson(js);
}

void AddPropertyTemplateArg::fromJson(const QJsonObject& js){

    PropertyGroupTemplate::fromJson(js);
}

QString AddPropertyTemplateArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<AddPropertyTemplateArg>  AddPropertyTemplateArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<AddPropertyTemplateArg>  AddPropertyTemplateArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<AddPropertyTemplateArg> rv;
    rv = std::unique_ptr<AddPropertyTemplateArg>(new AddPropertyTemplateArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
