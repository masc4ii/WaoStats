/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesFolderSharingInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///FolderSharingInfo

FolderSharingInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FolderSharingInfo::toJson(QJsonObject& js)const{

    SharingInfo::toJson(js);
    if(!m_parent_shared_folder_id.isEmpty())
        js["parent_shared_folder_id"] = QString(m_parent_shared_folder_id);
    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["traverse_only"] = m_traverse_only;
    js["no_access"] = m_no_access;
}

void FolderSharingInfo::fromJson(const QJsonObject& js){

    SharingInfo::fromJson(js);
    m_parent_shared_folder_id = js["parent_shared_folder_id"].toString();
    m_shared_folder_id = js["shared_folder_id"].toString();
    m_traverse_only = js["traverse_only"].toVariant().toBool();
    m_no_access = js["no_access"].toVariant().toBool();
}

QString FolderSharingInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FolderSharingInfo>  FolderSharingInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FolderSharingInfo>  FolderSharingInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FolderSharingInfo> rv;
    rv = std::unique_ptr<FolderSharingInfo>(new FolderSharingInfo);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
