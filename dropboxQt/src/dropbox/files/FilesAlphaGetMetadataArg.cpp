/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesAlphaGetMetadataArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///AlphaGetMetadataArg

AlphaGetMetadataArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void AlphaGetMetadataArg::toJson(QJsonObject& js)const{

    GetMetadataArg::toJson(js);
    js["include_property_templates"] = ingrl_list2jsonarray(m_include_property_templates);
}

void AlphaGetMetadataArg::fromJson(const QJsonObject& js){

    GetMetadataArg::fromJson(js);
    jsonarray2ingrl_list(js["include_property_templates"].toArray(), m_include_property_templates);
}

QString AlphaGetMetadataArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<AlphaGetMetadataArg>  AlphaGetMetadataArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<AlphaGetMetadataArg>  AlphaGetMetadataArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<AlphaGetMetadataArg> rv;
    rv = std::unique_ptr<AlphaGetMetadataArg>(new AlphaGetMetadataArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
