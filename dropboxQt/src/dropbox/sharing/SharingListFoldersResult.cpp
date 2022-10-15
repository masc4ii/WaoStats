/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFoldersResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFoldersResult

ListFoldersResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFoldersResult::toJson(QJsonObject& js)const{

    js["entries"] = struct_list2jsonarray(m_entries);
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListFoldersResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["entries"].toArray(), m_entries);
    m_cursor = js["cursor"].toString();
}

QString ListFoldersResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFoldersResult>  ListFoldersResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFoldersResult>  ListFoldersResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFoldersResult> rv;
    rv = std::unique_ptr<ListFoldersResult>(new ListFoldersResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
