/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMemberPermission.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///MemberPermission

MemberPermission::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MemberPermission::toJson(QJsonObject& js)const{

    m_action.toJson(js, "action");
    js["allow"] = m_allow;
    m_reason.toJson(js, "reason");
}

void MemberPermission::fromJson(const QJsonObject& js){

    m_action.fromJson(js["action"].toObject());
    m_allow = js["allow"].toVariant().toBool();
    m_reason.fromJson(js["reason"].toObject());
}

QString MemberPermission::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MemberPermission>  MemberPermission::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MemberPermission>  MemberPermission::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MemberPermission> rv;
    rv = std::unique_ptr<MemberPermission>(new MemberPermission);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
