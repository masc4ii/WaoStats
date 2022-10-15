/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesFileSharingInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///FileSharingInfo

FileSharingInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FileSharingInfo::toJson(QJsonObject& js)const{

    SharingInfo::toJson(js);
    if(!m_parent_shared_folder_id.isEmpty())
        js["parent_shared_folder_id"] = QString(m_parent_shared_folder_id);
    if(!m_modified_by.isEmpty())
        js["modified_by"] = QString(m_modified_by);
}

void FileSharingInfo::fromJson(const QJsonObject& js){

    SharingInfo::fromJson(js);
    m_parent_shared_folder_id = js["parent_shared_folder_id"].toString();
    m_modified_by = js["modified_by"].toString();
}

QString FileSharingInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FileSharingInfo>  FileSharingInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FileSharingInfo>  FileSharingInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FileSharingInfo> rv;
    rv = std::unique_ptr<FileSharingInfo>(new FileSharingInfo);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
