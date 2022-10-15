/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesThumbnailArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///ThumbnailArg

ThumbnailArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ThumbnailArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    m_format.toJson(js, "format");
    m_size.toJson(js, "size");
}

void ThumbnailArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_format.fromJson(js["format"].toObject());
    m_size.fromJson(js["size"].toObject());
}

QString ThumbnailArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ThumbnailArg>  ThumbnailArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ThumbnailArg>  ThumbnailArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ThumbnailArg> rv;
    rv = std::unique_ptr<ThumbnailArg>(new ThumbnailArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
