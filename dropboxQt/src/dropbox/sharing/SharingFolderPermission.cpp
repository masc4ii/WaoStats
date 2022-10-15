/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFolderPermission.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///FolderPermission

FolderPermission::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FolderPermission::toJson(QJsonObject& js)const{

    m_action.toJson(js, "action");
    js["allow"] = m_allow;
    m_reason.toJson(js, "reason");
}

void FolderPermission::fromJson(const QJsonObject& js){

    m_action.fromJson(js["action"].toObject());
    m_allow = js["allow"].toVariant().toBool();
    m_reason.fromJson(js["reason"].toObject());
}

QString FolderPermission::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FolderPermission>  FolderPermission::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FolderPermission>  FolderPermission::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FolderPermission> rv;
    rv = std::unique_ptr<FolderPermission>(new FolderPermission);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
