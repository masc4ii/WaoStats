/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamUpdatePropertyTemplateArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///UpdatePropertyTemplateArg

UpdatePropertyTemplateArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UpdatePropertyTemplateArg::toJson(QJsonObject& js)const{

    if(!m_template_id.isEmpty())
        js["template_id"] = QString(m_template_id);
    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(!m_description.isEmpty())
        js["description"] = QString(m_description);
    js["add_fields"] = struct_list2jsonarray(m_add_fields);
}

void UpdatePropertyTemplateArg::fromJson(const QJsonObject& js){

    m_template_id = js["template_id"].toString();
    m_name = js["name"].toString();
    m_description = js["description"].toString();
    jsonarray2struct_list(js["add_fields"].toArray(), m_add_fields);
}

QString UpdatePropertyTemplateArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UpdatePropertyTemplateArg>  UpdatePropertyTemplateArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UpdatePropertyTemplateArg>  UpdatePropertyTemplateArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UpdatePropertyTemplateArg> rv;
    rv = std::unique_ptr<UpdatePropertyTemplateArg>(new UpdatePropertyTemplateArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
