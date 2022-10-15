/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSearchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///SearchArg

SearchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SearchArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    if(!m_query.isEmpty())
        js["query"] = QString(m_query);
    js["start"] = QString("%1").arg(m_start);
    js["max_results"] = QString("%1").arg(m_max_results);
    m_mode.toJson(js, "mode");
}

void SearchArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_query = js["query"].toString();
    m_start = js["start"].toVariant().toString().toULongLong();
    m_max_results = js["max_results"].toVariant().toString().toULongLong();
    m_mode.fromJson(js["mode"].toObject());
}

QString SearchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SearchArg>  SearchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SearchArg>  SearchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SearchArg> rv;
    rv = std::unique_ptr<SearchArg>(new SearchArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
