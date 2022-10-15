/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesPropertyGroupUpdate.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///PropertyGroupUpdate

PropertyGroupUpdate::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PropertyGroupUpdate::toJson(QJsonObject& js)const{

    if(!m_template_id.isEmpty())
        js["template_id"] = QString(m_template_id);
    js["add_or_update_fields"] = struct_list2jsonarray(m_add_or_update_fields);
    js["remove_fields"] = ingrl_list2jsonarray(m_remove_fields);
}

void PropertyGroupUpdate::fromJson(const QJsonObject& js){

    m_template_id = js["template_id"].toString();
    jsonarray2struct_list(js["add_or_update_fields"].toArray(), m_add_or_update_fields);
    jsonarray2ingrl_list(js["remove_fields"].toArray(), m_remove_fields);
}

QString PropertyGroupUpdate::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PropertyGroupUpdate>  PropertyGroupUpdate::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PropertyGroupUpdate>  PropertyGroupUpdate::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PropertyGroupUpdate> rv;
    rv = std::unique_ptr<PropertyGroupUpdate>(new PropertyGroupUpdate);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
