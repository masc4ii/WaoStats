/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMemberAccessLevelResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///MemberAccessLevelResult

MemberAccessLevelResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MemberAccessLevelResult::toJson(QJsonObject& js)const{

    m_access_level.toJson(js, "access_level");
    if(!m_warning.isEmpty())
        js["warning"] = QString(m_warning);
    js["access_details"] = struct_list2jsonarray(m_access_details);
}

void MemberAccessLevelResult::fromJson(const QJsonObject& js){

    m_access_level.fromJson(js["access_level"].toObject());
    m_warning = js["warning"].toString();
    jsonarray2struct_list(js["access_details"].toArray(), m_access_details);
}

QString MemberAccessLevelResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MemberAccessLevelResult>  MemberAccessLevelResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MemberAccessLevelResult>  MemberAccessLevelResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MemberAccessLevelResult> rv;
    rv = std::unique_ptr<MemberAccessLevelResult>(new MemberAccessLevelResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
