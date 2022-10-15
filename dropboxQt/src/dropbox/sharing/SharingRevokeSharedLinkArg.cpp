/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRevokeSharedLinkArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///RevokeSharedLinkArg

RevokeSharedLinkArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeSharedLinkArg::toJson(QJsonObject& js)const{

    if(!m_url.isEmpty())
        js["url"] = QString(m_url);
}

void RevokeSharedLinkArg::fromJson(const QJsonObject& js){

    m_url = js["url"].toString();
}

QString RevokeSharedLinkArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeSharedLinkArg>  RevokeSharedLinkArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeSharedLinkArg>  RevokeSharedLinkArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeSharedLinkArg> rv;
    rv = std::unique_ptr<RevokeSharedLinkArg>(new RevokeSharedLinkArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
