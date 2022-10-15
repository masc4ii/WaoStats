/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersSpaceUsage.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///SpaceUsage

SpaceUsage::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SpaceUsage::toJson(QJsonObject& js)const{

    js["used"] = QString("%1").arg(m_used);
    m_allocation.toJson(js, "allocation");
}

void SpaceUsage::fromJson(const QJsonObject& js){

    m_used = js["used"].toVariant().toString().toULongLong();
    m_allocation.fromJson(js["allocation"].toObject());
}

QString SpaceUsage::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SpaceUsage>  SpaceUsage::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SpaceUsage>  SpaceUsage::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SpaceUsage> rv;
    rv = std::unique_ptr<SpaceUsage>(new SpaceUsage);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
