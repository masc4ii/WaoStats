/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesCommitInfoWithProperties.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///CommitInfoWithProperties

CommitInfoWithProperties::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void CommitInfoWithProperties::toJson(QJsonObject& js)const{

    CommitInfo::toJson(js);
    js["property_groups"] = struct_list2jsonarray(m_property_groups);
}

void CommitInfoWithProperties::fromJson(const QJsonObject& js){

    CommitInfo::fromJson(js);
    jsonarray2struct_list(js["property_groups"].toArray(), m_property_groups);
}

QString CommitInfoWithProperties::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<CommitInfoWithProperties>  CommitInfoWithProperties::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<CommitInfoWithProperties>  CommitInfoWithProperties::factory::create(const QJsonObject& js)
{
    std::unique_ptr<CommitInfoWithProperties> rv;
    rv = std::unique_ptr<CommitInfoWithProperties>(new CommitInfoWithProperties);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
