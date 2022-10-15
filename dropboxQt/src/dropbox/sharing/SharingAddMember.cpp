/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAddMember.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///AddMember

AddMember::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void AddMember::toJson(QJsonObject& js)const{

    m_member.toJson(js, "member");
    m_access_level.toJson(js, "access_level");
}

void AddMember::fromJson(const QJsonObject& js){

    m_member.fromJson(js["member"].toObject());
    m_access_level.fromJson(js["access_level"].toObject());
}

QString AddMember::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<AddMember>  AddMember::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<AddMember>  AddMember::factory::create(const QJsonObject& js)
{
    std::unique_ptr<AddMember> rv;
    rv = std::unique_ptr<AddMember>(new AddMember);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
