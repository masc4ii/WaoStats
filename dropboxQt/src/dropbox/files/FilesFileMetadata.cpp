/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesFileMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///FileMetadata

FileMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FileMetadata::toJson(QJsonObject& js)const{

    Metadata::toJson(js);
    if(!m_id.isEmpty())
        js["id"] = QString(m_id);
    if(m_client_modified.isValid())
        js["client_modified"] = m_client_modified.toString("yyyy-MM-ddThh:mm:ssZ");
    if(m_server_modified.isValid())
        js["server_modified"] = m_server_modified.toString("yyyy-MM-ddThh:mm:ssZ");
    if(!m_rev.isEmpty())
        js["rev"] = QString(m_rev);
    js["size"] = QString("%1").arg(m_size);
    m_media_info.toJson(js, "media_info");
    js["sharing_info"] = (QJsonObject)m_sharing_info;
    js["property_groups"] = struct_list2jsonarray(m_property_groups);
    js["has_explicit_shared_members"] = m_has_explicit_shared_members;
}

void FileMetadata::fromJson(const QJsonObject& js){

    Metadata::fromJson(js);
    m_id = js["id"].toString();
    m_client_modified = QDateTime::fromString(js["client_modified"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_server_modified = QDateTime::fromString(js["server_modified"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_rev = js["rev"].toString();
    m_size = js["size"].toVariant().toString().toULongLong();
    m_media_info.fromJson(js["media_info"].toObject());
    m_sharing_info.fromJson(js["sharing_info"].toObject());
    jsonarray2struct_list(js["property_groups"].toArray(), m_property_groups);
    m_has_explicit_shared_members = js["has_explicit_shared_members"].toVariant().toBool();
}

QString FileMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FileMetadata>  FileMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FileMetadata>  FileMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FileMetadata> rv;
    rv = std::unique_ptr<FileMetadata>(new FileMetadata);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
