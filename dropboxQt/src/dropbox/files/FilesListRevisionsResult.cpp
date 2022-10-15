/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesListRevisionsResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///ListRevisionsResult

ListRevisionsResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListRevisionsResult::toJson(QJsonObject& js)const{

    js["is_deleted"] = m_is_deleted;
    js["entries"] = struct_list2jsonarray(m_entries);
}

void ListRevisionsResult::fromJson(const QJsonObject& js){

    m_is_deleted = js["is_deleted"].toVariant().toBool();
    jsonarray2struct_list(js["entries"].toArray(), m_entries);
}

QString ListRevisionsResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListRevisionsResult>  ListRevisionsResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListRevisionsResult>  ListRevisionsResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListRevisionsResult> rv;
    rv = std::unique_ptr<ListRevisionsResult>(new ListRevisionsResult);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
