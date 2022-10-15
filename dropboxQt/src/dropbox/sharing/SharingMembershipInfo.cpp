/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMembershipInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///MembershipInfo

MembershipInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembershipInfo::toJson(QJsonObject& js)const{

    m_access_type.toJson(js, "access_type");
    js["permissions"] = struct_list2jsonarray(m_permissions);
    if(!m_initials.isEmpty())
        js["initials"] = QString(m_initials);
    js["is_inherited"] = m_is_inherited;
}

void MembershipInfo::fromJson(const QJsonObject& js){

    m_access_type.fromJson(js["access_type"].toObject());
    jsonarray2struct_list(js["permissions"].toArray(), m_permissions);
    m_initials = js["initials"].toString();
    m_is_inherited = js["is_inherited"].toVariant().toBool();
}

QString MembershipInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembershipInfo>  MembershipInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembershipInfo>  MembershipInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembershipInfo> rv;
    rv = std::unique_ptr<MembershipInfo>(new MembershipInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
