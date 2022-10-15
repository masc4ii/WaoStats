/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMemberAccess.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MemberAccess

MemberAccess::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MemberAccess::toJson(QJsonObject& js)const{

    m_user.toJson(js, "user");
    m_access_type.toJson(js, "access_type");
}

void MemberAccess::fromJson(const QJsonObject& js){

    m_user.fromJson(js["user"].toObject());
    m_access_type.fromJson(js["access_type"].toObject());
}

QString MemberAccess::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MemberAccess>  MemberAccess::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MemberAccess>  MemberAccess::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MemberAccess> rv;
    rv = std::unique_ptr<MemberAccess>(new MemberAccess);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
