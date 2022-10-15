/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUpdatePropertyGroupArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///UpdatePropertyGroupArg

UpdatePropertyGroupArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UpdatePropertyGroupArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    js["update_property_groups"] = struct_list2jsonarray(m_update_property_groups);
}

void UpdatePropertyGroupArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    jsonarray2struct_list(js["update_property_groups"].toArray(), m_update_property_groups);
}

QString UpdatePropertyGroupArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UpdatePropertyGroupArg>  UpdatePropertyGroupArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UpdatePropertyGroupArg>  UpdatePropertyGroupArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UpdatePropertyGroupArg> rv;
    rv = std::unique_ptr<UpdatePropertyGroupArg>(new UpdatePropertyGroupArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
