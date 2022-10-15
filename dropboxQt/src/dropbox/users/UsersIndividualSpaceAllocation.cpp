/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersIndividualSpaceAllocation.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///IndividualSpaceAllocation

IndividualSpaceAllocation::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void IndividualSpaceAllocation::toJson(QJsonObject& js)const{

    js["allocated"] = QString("%1").arg(m_allocated);
}

void IndividualSpaceAllocation::fromJson(const QJsonObject& js){

    m_allocated = js["allocated"].toVariant().toString().toULongLong();
}

QString IndividualSpaceAllocation::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<IndividualSpaceAllocation>  IndividualSpaceAllocation::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<IndividualSpaceAllocation>  IndividualSpaceAllocation::factory::create(const QJsonObject& js)
{
    std::unique_ptr<IndividualSpaceAllocation> rv;
    rv = std::unique_ptr<IndividualSpaceAllocation>(new IndividualSpaceAllocation);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
