/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetSharedLinksResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetSharedLinksResult

GetSharedLinksResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetSharedLinksResult::toJson(QJsonObject& js)const{

    js["links"] = struct_list2jsonarray(m_links);
}

void GetSharedLinksResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["links"].toArray(), m_links);
}

QString GetSharedLinksResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetSharedLinksResult>  GetSharedLinksResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetSharedLinksResult>  GetSharedLinksResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetSharedLinksResult> rv;
    rv = std::unique_ptr<GetSharedLinksResult>(new GetSharedLinksResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
