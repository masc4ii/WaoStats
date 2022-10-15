/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesMetadata.h"
#include "dropbox/files/FilesFileMetadata.h"
#include "dropbox/files/FilesFolderMetadata.h"
#include "dropbox/files/FilesDeletedMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///Metadata

Metadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void Metadata::toJson(QJsonObject& js)const{

    if(!m_name.isEmpty())
        js["name"] = QString(m_name);
    if(!m_path_lower.isEmpty())
        js["path_lower"] = QString(m_path_lower);
    if(!m_path_display.isEmpty())
        js["path_display"] = QString(m_path_display);
    if(!m_parent_shared_folder_id.isEmpty())
        js["parent_shared_folder_id"] = QString(m_parent_shared_folder_id);
}

void Metadata::fromJson(const QJsonObject& js){

    m_name = js["name"].toString();
    m_path_lower = js["path_lower"].toString();
    m_path_display = js["path_display"].toString();
    m_parent_shared_folder_id = js["parent_shared_folder_id"].toString();
}

QString Metadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<Metadata>  Metadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<Metadata>  Metadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<Metadata> rv;
    // subtype ('file',) : FileMetadata
    // subtype ('folder',) : FolderMetadata
    // subtype ('deleted',) : DeletedMetadata
    QString tag = js[".tag"].toString();
    if(tag.isEmpty()){
        rv = std::unique_ptr<Metadata>(new Metadata);
    }else if(tag.compare("file") == 0){
        rv = std::unique_ptr<Metadata>(new FileMetadata);
    }else if(tag.compare("folder") == 0){
        rv = std::unique_ptr<Metadata>(new FolderMetadata);
    }else if(tag.compare("deleted") == 0){
        rv = std::unique_ptr<Metadata>(new DeletedMetadata);
    }
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
