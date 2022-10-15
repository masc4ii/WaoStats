/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersSetPermissionsArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersSetPermissionsArg

MembersSetPermissionsArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersSetPermissionsArg::toJson(QJsonObject& js)const{

    m_user.toJson(js, "user");
    m_new_role.toJson(js, "new_role");
}

void MembersSetPermissionsArg::fromJson(const QJsonObject& js){

    m_user.fromJson(js["user"].toObject());
    m_new_role.fromJson(js["new_role"].toObject());
}

QString MembersSetPermissionsArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersSetPermissionsArg>  MembersSetPermissionsArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersSetPermissionsArg>  MembersSetPermissionsArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersSetPermissionsArg> rv;
    rv = std::unique_ptr<MembersSetPermissionsArg>(new MembersSetPermissionsArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
