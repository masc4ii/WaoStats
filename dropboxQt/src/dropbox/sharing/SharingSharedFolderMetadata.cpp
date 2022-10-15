/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedFolderMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///SharedFolderMetadata

SharedFolderMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SharedFolderMetadata::toJson(QJsonObject& js)const{

    SharedFolderMetadataBase::toJson(js);
    if(!m_path_lower.isEmpty())
        js["path_lower"] = QString(m_path_lower);
    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["permissions"] = struct_list2jsonarray(m_permissions);
    if(m_time_invited.isValid())
        js["time_invited"] = m_time_invited.toString("yyyy-MM-ddThh:mm:ssZ");
    if(!m_preview_url.isEmpty())
        js["preview_url"] = QString(m_preview_url);
}

void SharedFolderMetadata::fromJson(const QJsonObject& js){

    SharedFolderMetadataBase::fromJson(js);
    m_path_lower = js["path_lower"].toString();
    m_name = js["name"].toString();
    m_shared_folder_id = js["shared_folder_id"].toString();
    jsonarray2struct_list(js["permissions"].toArray(), m_permissions);
    m_time_invited = QDateTime::fromString(js["time_invited"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_preview_url = js["preview_url"].toString();
}

QString SharedFolderMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SharedFolderMetadata>  SharedFolderMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SharedFolderMetadata>  SharedFolderMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SharedFolderMetadata> rv;
    rv = std::unique_ptr<SharedFolderMetadata>(new SharedFolderMetadata);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
