/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesMediaInfo.h"

namespace dropboxQt{

namespace files{
///MediaInfo

MediaInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MediaInfo::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MediaInfo_PENDING:{
            if(!name.isEmpty())
                js[name] = QString("pending");
        }break;
        case MediaInfo_METADATA:{
            if(!name.isEmpty())
                js[name] = QString("metadata");
            js["metadata"] = (QJsonObject)m_metadata;
        }break;
    }//switch
}

void MediaInfo::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("pending") == 0){
        m_tag = MediaInfo_PENDING;

    }
    else if(s.compare("metadata") == 0){
        m_tag = MediaInfo_METADATA;
        m_metadata.fromJson(js["metadata"].toObject());
    }
}

QString MediaInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MediaInfo");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MediaInfo>  MediaInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MediaInfo> rv = std::unique_ptr<MediaInfo>(new MediaInfo);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
