/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingCreateSharedLinkArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///CreateSharedLinkArg

CreateSharedLinkArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void CreateSharedLinkArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    js["short_url"] = m_short_url;
    m_pending_upload.toJson(js, "pending_upload");
}

void CreateSharedLinkArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_short_url = js["short_url"].toVariant().toBool();
    m_pending_upload.fromJson(js["pending_upload"].toObject());
}

QString CreateSharedLinkArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<CreateSharedLinkArg>  CreateSharedLinkArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<CreateSharedLinkArg>  CreateSharedLinkArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<CreateSharedLinkArg> rv;
    rv = std::unique_ptr<CreateSharedLinkArg>(new CreateSharedLinkArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
