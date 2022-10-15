/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesPropertyGroupWithPath.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///PropertyGroupWithPath

PropertyGroupWithPath::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PropertyGroupWithPath::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    js["property_groups"] = struct_list2jsonarray(m_property_groups);
}

void PropertyGroupWithPath::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    jsonarray2struct_list(js["property_groups"].toArray(), m_property_groups);
}

QString PropertyGroupWithPath::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PropertyGroupWithPath>  PropertyGroupWithPath::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PropertyGroupWithPath>  PropertyGroupWithPath::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PropertyGroupWithPath> rv;
    rv = std::unique_ptr<PropertyGroupWithPath>(new PropertyGroupWithPath);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
