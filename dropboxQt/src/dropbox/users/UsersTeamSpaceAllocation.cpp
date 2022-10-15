/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersTeamSpaceAllocation.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///TeamSpaceAllocation

TeamSpaceAllocation::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void TeamSpaceAllocation::toJson(QJsonObject& js)const{

    js["used"] = QString("%1").arg(m_used);
    js["allocated"] = QString("%1").arg(m_allocated);
}

void TeamSpaceAllocation::fromJson(const QJsonObject& js){

    m_used = js["used"].toVariant().toString().toULongLong();
    m_allocated = js["allocated"].toVariant().toString().toULongLong();
}

QString TeamSpaceAllocation::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<TeamSpaceAllocation>  TeamSpaceAllocation::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<TeamSpaceAllocation>  TeamSpaceAllocation::factory::create(const QJsonObject& js)
{
    std::unique_ptr<TeamSpaceAllocation> rv;
    rv = std::unique_ptr<TeamSpaceAllocation>(new TeamSpaceAllocation);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
