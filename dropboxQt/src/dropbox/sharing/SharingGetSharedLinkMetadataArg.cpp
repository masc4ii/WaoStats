/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetSharedLinkMetadataArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetSharedLinkMetadataArg

GetSharedLinkMetadataArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetSharedLinkMetadataArg::toJson(QJsonObject& js)const{

    if(!m_url.isEmpty())
        js["url"] = QString(m_url);
    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    if(!m_link_password.isEmpty())
        js["link_password"] = QString(m_link_password);
}

void GetSharedLinkMetadataArg::fromJson(const QJsonObject& js){

    m_url = js["url"].toString();
    m_path = js["path"].toString();
    m_link_password = js["link_password"].toString();
}

QString GetSharedLinkMetadataArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetSharedLinkMetadataArg>  GetSharedLinkMetadataArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetSharedLinkMetadataArg>  GetSharedLinkMetadataArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetSharedLinkMetadataArg> rv;
    rv = std::unique_ptr<GetSharedLinkMetadataArg>(new GetSharedLinkMetadataArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
