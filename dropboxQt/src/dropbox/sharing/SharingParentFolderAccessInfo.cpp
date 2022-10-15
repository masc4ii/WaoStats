/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingParentFolderAccessInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ParentFolderAccessInfo

ParentFolderAccessInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ParentFolderAccessInfo::toJson(QJsonObject& js)const{

    if(!m_folder_name.isEmpty())
        js["folder_name"] = QString(m_folder_name);
    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["permissions"] = struct_list2jsonarray(m_permissions);
}

void ParentFolderAccessInfo::fromJson(const QJsonObject& js){

    m_folder_name = js["folder_name"].toString();
    m_shared_folder_id = js["shared_folder_id"].toString();
    jsonarray2struct_list(js["permissions"].toArray(), m_permissions);
}

QString ParentFolderAccessInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ParentFolderAccessInfo>  ParentFolderAccessInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ParentFolderAccessInfo>  ParentFolderAccessInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ParentFolderAccessInfo> rv;
    rv = std::unique_ptr<ParentFolderAccessInfo>(new ParentFolderAccessInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
