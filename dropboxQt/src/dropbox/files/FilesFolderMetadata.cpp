/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesFolderMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///FolderMetadata

FolderMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FolderMetadata::toJson(QJsonObject& js)const{

    Metadata::toJson(js);
    if(!m_id.isEmpty())
        js["id"] = QString(m_id);
    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["sharing_info"] = (QJsonObject)m_sharing_info;
    js["property_groups"] = struct_list2jsonarray(m_property_groups);
}

void FolderMetadata::fromJson(const QJsonObject& js){

    Metadata::fromJson(js);
    m_id = js["id"].toString();
    m_shared_folder_id = js["shared_folder_id"].toString();
    m_sharing_info.fromJson(js["sharing_info"].toObject());
    jsonarray2struct_list(js["property_groups"].toArray(), m_property_groups);
}

QString FolderMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FolderMetadata>  FolderMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FolderMetadata>  FolderMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FolderMetadata> rv;
    rv = std::unique_ptr<FolderMetadata>(new FolderMetadata);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
