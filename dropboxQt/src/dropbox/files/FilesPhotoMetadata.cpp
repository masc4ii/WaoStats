/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesPhotoMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///PhotoMetadata

PhotoMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PhotoMetadata::toJson(QJsonObject& js)const{

    MediaMetadata::toJson(js);
}

void PhotoMetadata::fromJson(const QJsonObject& js){

    MediaMetadata::fromJson(js);
}

QString PhotoMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PhotoMetadata>  PhotoMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PhotoMetadata>  PhotoMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PhotoMetadata> rv;
    rv = std::unique_ptr<PhotoMetadata>(new PhotoMetadata);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
