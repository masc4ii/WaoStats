/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamBaseDfbReport.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///BaseDfbReport

BaseDfbReport::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void BaseDfbReport::toJson(QJsonObject& js)const{

    if(!m_start_date.isEmpty())
        js["start_date"] = QString(m_start_date);
}

void BaseDfbReport::fromJson(const QJsonObject& js){

    m_start_date = js["start_date"].toString();
}

QString BaseDfbReport::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<BaseDfbReport>  BaseDfbReport::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<BaseDfbReport>  BaseDfbReport::factory::create(const QJsonObject& js)
{
    std::unique_ptr<BaseDfbReport> rv;
    rv = std::unique_ptr<BaseDfbReport>(new BaseDfbReport);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
