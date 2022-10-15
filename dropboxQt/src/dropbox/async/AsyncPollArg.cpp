/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/async/AsyncPollArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace async{
///PollArg

PollArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void PollArg::toJson(QJsonObject& js)const{

    if(!m_async_job_id.isEmpty())
        js["async_job_id"] = QString(m_async_job_id);
}

void PollArg::fromJson(const QJsonObject& js){

    m_async_job_id = js["async_job_id"].toString();
}

QString PollArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<PollArg>  PollArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<PollArg>  PollArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<PollArg> rv;
    rv = std::unique_ptr<PollArg>(new PollArg);
    rv->fromJson(js);
    return rv;
}

}//async
}//dropboxQt
