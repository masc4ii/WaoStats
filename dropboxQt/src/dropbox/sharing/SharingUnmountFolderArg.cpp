/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUnmountFolderArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///UnmountFolderArg

UnmountFolderArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UnmountFolderArg::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
}

void UnmountFolderArg::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
}

QString UnmountFolderArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UnmountFolderArg>  UnmountFolderArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UnmountFolderArg>  UnmountFolderArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UnmountFolderArg> rv;
    rv = std::unique_ptr<UnmountFolderArg>(new UnmountFolderArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
