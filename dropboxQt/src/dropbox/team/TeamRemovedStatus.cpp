/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRemovedStatus.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RemovedStatus

RemovedStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RemovedStatus::toJson(QJsonObject& js)const{

    js["is_recoverable"] = m_is_recoverable;
}

void RemovedStatus::fromJson(const QJsonObject& js){

    m_is_recoverable = js["is_recoverable"].toVariant().toBool();
}

QString RemovedStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RemovedStatus>  RemovedStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RemovedStatus>  RemovedStatus::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RemovedStatus> rv;
    rv = std::unique_ptr<RemovedStatus>(new RemovedStatus);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
