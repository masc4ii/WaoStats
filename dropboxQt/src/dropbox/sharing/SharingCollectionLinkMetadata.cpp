/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingCollectionLinkMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///CollectionLinkMetadata

CollectionLinkMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void CollectionLinkMetadata::toJson(QJsonObject& js)const{

    LinkMetadata::toJson(js);
}

void CollectionLinkMetadata::fromJson(const QJsonObject& js){

    LinkMetadata::fromJson(js);
}

QString CollectionLinkMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<CollectionLinkMetadata>  CollectionLinkMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<CollectionLinkMetadata>  CollectionLinkMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<CollectionLinkMetadata> rv;
    rv = std::unique_ptr<CollectionLinkMetadata>(new CollectionLinkMetadata);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
