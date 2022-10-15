/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesThumbnailFormat.h"

namespace dropboxQt{

namespace files{
///ThumbnailFormat

ThumbnailFormat::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ThumbnailFormat::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ThumbnailFormat_JPEG:{
            if(!name.isEmpty())
                js[name] = QString("jpeg");
        }break;
        case ThumbnailFormat_PNG:{
            if(!name.isEmpty())
                js[name] = QString("png");
        }break;
    }//switch
}

void ThumbnailFormat::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("jpeg") == 0){
        m_tag = ThumbnailFormat_JPEG;

    }
    else if(s.compare("png") == 0){
        m_tag = ThumbnailFormat_PNG;

    }
}

QString ThumbnailFormat::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ThumbnailFormat");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ThumbnailFormat>  ThumbnailFormat::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ThumbnailFormat> rv = std::unique_ptr<ThumbnailFormat>(new ThumbnailFormat);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
