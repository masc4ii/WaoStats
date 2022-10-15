/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedFolderMetadataBase.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///SharedFolderMetadataBase

SharedFolderMetadataBase::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SharedFolderMetadataBase::toJson(QJsonObject& js)const{

    m_access_type.toJson(js, "access_type");
    js["is_team_folder"] = m_is_team_folder;
    js["policy"] = (QJsonObject)m_policy;
    js["owner_team"] = (QJsonObject)m_owner_team;
    if(!m_parent_shared_folder_id.isEmpty())
        js["parent_shared_folder_id"] = QString(m_parent_shared_folder_id);
}

void SharedFolderMetadataBase::fromJson(const QJsonObject& js){

    m_access_type.fromJson(js["access_type"].toObject());
    m_is_team_folder = js["is_team_folder"].toVariant().toBool();
    m_policy.fromJson(js["policy"].toObject());
    m_owner_team.fromJson(js["owner_team"].toObject());
    m_parent_shared_folder_id = js["parent_shared_folder_id"].toString();
}

QString SharedFolderMetadataBase::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SharedFolderMetadataBase>  SharedFolderMetadataBase::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SharedFolderMetadataBase>  SharedFolderMetadataBase::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SharedFolderMetadataBase> rv;
    rv = std::unique_ptr<SharedFolderMetadataBase>(new SharedFolderMetadataBase);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
