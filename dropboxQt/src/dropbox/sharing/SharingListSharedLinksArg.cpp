/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListSharedLinksArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListSharedLinksArg

ListSharedLinksArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListSharedLinksArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
    js["direct_only"] = m_direct_only;
}

void ListSharedLinksArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_cursor = js["cursor"].toString();
    m_direct_only = js["direct_only"].toVariant().toBool();
}

QString ListSharedLinksArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListSharedLinksArg>  ListSharedLinksArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListSharedLinksArg>  ListSharedLinksArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListSharedLinksArg> rv;
    rv = std::unique_ptr<ListSharedLinksArg>(new ListSharedLinksArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
