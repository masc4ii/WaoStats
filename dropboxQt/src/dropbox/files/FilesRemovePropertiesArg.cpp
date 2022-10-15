/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesRemovePropertiesArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///RemovePropertiesArg

RemovePropertiesArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RemovePropertiesArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    js["property_template_ids"] = ingrl_list2jsonarray(m_property_template_ids);
}

void RemovePropertiesArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    jsonarray2ingrl_list(js["property_template_ids"].toArray(), m_property_template_ids);
}

QString RemovePropertiesArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RemovePropertiesArg>  RemovePropertiesArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RemovePropertiesArg>  RemovePropertiesArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RemovePropertiesArg> rv;
    rv = std::unique_ptr<RemovePropertiesArg>(new RemovePropertiesArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
