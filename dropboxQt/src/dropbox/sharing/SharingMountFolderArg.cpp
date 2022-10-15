/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMountFolderArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///MountFolderArg

MountFolderArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MountFolderArg::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
}

void MountFolderArg::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
}

QString MountFolderArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MountFolderArg>  MountFolderArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MountFolderArg>  MountFolderArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MountFolderArg> rv;
    rv = std::unique_ptr<MountFolderArg>(new MountFolderArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
