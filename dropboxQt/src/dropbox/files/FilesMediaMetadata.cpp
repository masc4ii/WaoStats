/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesMediaMetadata.h"
#include "dropbox/files/FilesPhotoMetadata.h"
#include "dropbox/files/FilesVideoMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///MediaMetadata

MediaMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MediaMetadata::toJson(QJsonObject& js)const{

    js["dimensions"] = (QJsonObject)m_dimensions;
    js["location"] = (QJsonObject)m_location;
    if(m_time_taken.isValid())
        js["time_taken"] = m_time_taken.toString("yyyy-MM-ddThh:mm:ssZ");
}

void MediaMetadata::fromJson(const QJsonObject& js){

    m_dimensions.fromJson(js["dimensions"].toObject());
    m_location.fromJson(js["location"].toObject());
    m_time_taken = QDateTime::fromString(js["time_taken"].toString(), "yyyy-MM-ddThh:mm:ssZ");
}

QString MediaMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MediaMetadata>  MediaMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MediaMetadata>  MediaMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MediaMetadata> rv;
    // subtype ('photo',) : PhotoMetadata
    // subtype ('video',) : VideoMetadata
    QString tag = js[".tag"].toString();
    if(tag.isEmpty()){
        rv = std::unique_ptr<MediaMetadata>(new MediaMetadata);
    }else if(tag.compare("photo") == 0){
        rv = std::unique_ptr<MediaMetadata>(new PhotoMetadata);
    }else if(tag.compare("video") == 0){
        rv = std::unique_ptr<MediaMetadata>(new VideoMetadata);
    }
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
