/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedLinkMetadata.h"
#include "dropbox/sharing/SharingFileLinkMetadata.h"
#include "dropbox/sharing/SharingFolderLinkMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///SharedLinkMetadata

SharedLinkMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SharedLinkMetadata::toJson(QJsonObject& js)const{

    if(!m_url.isEmpty())
        js["url"] = QString(m_url);
    if(!m_id.isEmpty())
        js["id"] = QString(m_id);
    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(m_expires.isValid())
        js["expires"] = m_expires.toString("yyyy-MM-ddThh:mm:ssZ");
    if(!m_path_lower.isEmpty())
        js["path_lower"] = QString(m_path_lower);
    js["link_permissions"] = (QJsonObject)m_link_permissions;
    js["team_member_info"] = (QJsonObject)m_team_member_info;
    js["content_owner_team_info"] = (QJsonObject)m_content_owner_team_info;
}

void SharedLinkMetadata::fromJson(const QJsonObject& js){

    m_url = js["url"].toString();
    m_id = js["id"].toString();
    m_name = js["name"].toString();
    m_expires = QDateTime::fromString(js["expires"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_path_lower = js["path_lower"].toString();
    m_link_permissions.fromJson(js["link_permissions"].toObject());
    m_team_member_info.fromJson(js["team_member_info"].toObject());
    m_content_owner_team_info.fromJson(js["content_owner_team_info"].toObject());
}

QString SharedLinkMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SharedLinkMetadata>  SharedLinkMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SharedLinkMetadata>  SharedLinkMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SharedLinkMetadata> rv;
    // subtype ('file',) : FileLinkMetadata
    // subtype ('folder',) : FolderLinkMetadata
    QString tag = js[".tag"].toString();
    if(tag.isEmpty()){
        rv = std::unique_ptr<SharedLinkMetadata>(new SharedLinkMetadata);
    }else if(tag.compare("file") == 0){
        rv = std::unique_ptr<SharedLinkMetadata>(new FileLinkMetadata);
    }else if(tag.compare("folder") == 0){
        rv = std::unique_ptr<SharedLinkMetadata>(new FolderLinkMetadata);
    }
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
