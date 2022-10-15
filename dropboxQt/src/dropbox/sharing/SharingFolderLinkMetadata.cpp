/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFolderLinkMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///FolderLinkMetadata

FolderLinkMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FolderLinkMetadata::toJson(QJsonObject& js)const{

    SharedLinkMetadata::toJson(js);
}

void FolderLinkMetadata::fromJson(const QJsonObject& js){

    SharedLinkMetadata::fromJson(js);
}

QString FolderLinkMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FolderLinkMetadata>  FolderLinkMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FolderLinkMetadata>  FolderLinkMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FolderLinkMetadata> rv;
    rv = std::unique_ptr<FolderLinkMetadata>(new FolderLinkMetadata);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
