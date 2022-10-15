/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetSharedLinksArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetSharedLinksArg

GetSharedLinksArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetSharedLinksArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
}

void GetSharedLinksArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
}

QString GetSharedLinksArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetSharedLinksArg>  GetSharedLinksArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetSharedLinksArg>  GetSharedLinksArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetSharedLinksArg> rv;
    rv = std::unique_ptr<GetSharedLinksArg>(new GetSharedLinksArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
