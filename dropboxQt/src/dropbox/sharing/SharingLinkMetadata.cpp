/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingLinkMetadata.h"
#include "dropbox/sharing/SharingPathLinkMetadata.h"
#include "dropbox/sharing/SharingCollectionLinkMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///LinkMetadata

LinkMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void LinkMetadata::toJson(QJsonObject& js)const{

    if(!m_url.isEmpty())
        js["url"] = QString(m_url);
    m_visibility.toJson(js, "visibility");
    if(m_expires.isValid())
        js["expires"] = m_expires.toString("yyyy-MM-ddThh:mm:ssZ");
}

void LinkMetadata::fromJson(const QJsonObject& js){

    m_url = js["url"].toString();
    m_visibility.fromJson(js["visibility"].toObject());
    m_expires = QDateTime::fromString(js["expires"].toString(), "yyyy-MM-ddThh:mm:ssZ");
}

QString LinkMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<LinkMetadata>  LinkMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<LinkMetadata>  LinkMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<LinkMetadata> rv;
    // subtype ('path',) : PathLinkMetadata
    // subtype ('collection',) : CollectionLinkMetadata
    QString tag = js[".tag"].toString();
    if(tag.isEmpty()){
        rv = std::unique_ptr<LinkMetadata>(new LinkMetadata);
    }else if(tag.compare("path") == 0){
        rv = std::unique_ptr<LinkMetadata>(new PathLinkMetadata);
    }else if(tag.compare("collection") == 0){
        rv = std::unique_ptr<LinkMetadata>(new CollectionLinkMetadata);
    }
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
