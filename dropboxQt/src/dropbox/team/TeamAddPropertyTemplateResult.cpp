/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamAddPropertyTemplateResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///AddPropertyTemplateResult

AddPropertyTemplateResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void AddPropertyTemplateResult::toJson(QJsonObject& js)const{

    if(!m_template_id.isEmpty())
        js["template_id"] = QString(m_template_id);
}

void AddPropertyTemplateResult::fromJson(const QJsonObject& js){

    m_template_id = js["template_id"].toString();
}

QString AddPropertyTemplateResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<AddPropertyTemplateResult>  AddPropertyTemplateResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<AddPropertyTemplateResult>  AddPropertyTemplateResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<AddPropertyTemplateResult> rv;
    rv = std::unique_ptr<AddPropertyTemplateResult>(new AddPropertyTemplateResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
