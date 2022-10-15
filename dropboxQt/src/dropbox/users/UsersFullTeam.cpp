/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersFullTeam.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///FullTeam

FullTeam::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FullTeam::toJson(QJsonObject& js)const{

    Team::toJson(js);
    js["sharing_policies"] = (QJsonObject)m_sharing_policies;
}

void FullTeam::fromJson(const QJsonObject& js){

    Team::fromJson(js);
    m_sharing_policies.fromJson(js["sharing_policies"].toObject());
}

QString FullTeam::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FullTeam>  FullTeam::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FullTeam>  FullTeam::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FullTeam> rv;
    rv = std::unique_ptr<FullTeam>(new FullTeam);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
