/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesListFolderResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///ListFolderResult

ListFolderResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFolderResult::toJson(QJsonObject& js)const{

    js["entries"] = struct_list2jsonarray_uptr(m_entries);
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
    js["has_more"] = m_has_more;
}

void ListFolderResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list_uptr(js["entries"].toArray(), m_entries);
    m_cursor = js["cursor"].toString();
    m_has_more = js["has_more"].toVariant().toBool();
}

QString ListFolderResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFolderResult>  ListFolderResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFolderResult>  ListFolderResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFolderResult> rv;
    rv = std::unique_ptr<ListFolderResult>(new ListFolderResult);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
