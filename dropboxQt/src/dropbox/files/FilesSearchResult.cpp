/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSearchResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///SearchResult

SearchResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SearchResult::toJson(QJsonObject& js)const{

    js["matches"] = struct_list2jsonarray(m_matches);
    js["more"] = m_more;
    js["start"] = QString("%1").arg(m_start);
}

void SearchResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["matches"].toArray(), m_matches);
    m_more = js["more"].toVariant().toBool();
    m_start = js["start"].toVariant().toString().toULongLong();
}

QString SearchResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SearchResult>  SearchResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SearchResult>  SearchResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SearchResult> rv;
    rv = std::unique_ptr<SearchResult>(new SearchResult);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
