/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFileLinkMetadata.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///FileLinkMetadata

FileLinkMetadata::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FileLinkMetadata::toJson(QJsonObject& js)const{

    SharedLinkMetadata::toJson(js);
    if(m_client_modified.isValid())
        js["client_modified"] = m_client_modified.toString("yyyy-MM-ddThh:mm:ssZ");
    if(m_server_modified.isValid())
        js["server_modified"] = m_server_modified.toString("yyyy-MM-ddThh:mm:ssZ");
    if(!m_rev.isEmpty())
        js["rev"] = QString(m_rev);
    js["size"] = QString("%1").arg(m_size);
}

void FileLinkMetadata::fromJson(const QJsonObject& js){

    SharedLinkMetadata::fromJson(js);
    m_client_modified = QDateTime::fromString(js["client_modified"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_server_modified = QDateTime::fromString(js["server_modified"].toString(), "yyyy-MM-ddThh:mm:ssZ");
    m_rev = js["rev"].toString();
    m_size = js["size"].toVariant().toString().toULongLong();
}

QString FileLinkMetadata::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FileLinkMetadata>  FileLinkMetadata::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FileLinkMetadata>  FileLinkMetadata::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FileLinkMetadata> rv;
    rv = std::unique_ptr<FileLinkMetadata>(new FileLinkMetadata);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
