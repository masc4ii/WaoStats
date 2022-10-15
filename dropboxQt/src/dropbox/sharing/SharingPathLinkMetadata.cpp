/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingPathLinkMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///PathLinkMetadata

PathLinkMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PathLinkMetadata::toJson(QJsonObject& js)const{

    LinkMetadata::toJson(js);
    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
}

void PathLinkMetadata::fromJson(const QJsonObject& js){

    LinkMetadata::fromJson(js);
    m_path = js["path"].toString();
}

QString PathLinkMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PathLinkMetadata>  PathLinkMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PathLinkMetadata>  PathLinkMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PathLinkMetadata> rv;
    rv = std::unique_ptr<PathLinkMetadata>(new PathLinkMetadata);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
