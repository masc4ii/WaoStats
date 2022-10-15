/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListSharedLinksResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListSharedLinksResult

ListSharedLinksResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListSharedLinksResult::toJson(QJsonObject& js)const{

    js["links"] = struct_list2jsonarray(m_links);
    js["has_more"] = m_has_more;
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListSharedLinksResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["links"].toArray(), m_links);
    m_has_more = js["has_more"].toVariant().toBool();
    m_cursor = js["cursor"].toString();
}

QString ListSharedLinksResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListSharedLinksResult>  ListSharedLinksResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListSharedLinksResult>  ListSharedLinksResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListSharedLinksResult> rv;
    rv = std::unique_ptr<ListSharedLinksResult>(new ListSharedLinksResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
