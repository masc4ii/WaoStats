/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersRecoverArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersRecoverArg

MembersRecoverArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersRecoverArg::toJson(QJsonObject& js)const{

    m_user.toJson(js, "user");
}

void MembersRecoverArg::fromJson(const QJsonObject& js){

    m_user.fromJson(js["user"].toObject());
}

QString MembersRecoverArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersRecoverArg>  MembersRecoverArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersRecoverArg>  MembersRecoverArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersRecoverArg> rv;
    rv = std::unique_ptr<MembersRecoverArg>(new MembersRecoverArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
