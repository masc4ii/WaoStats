/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMemberAddArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MemberAddArg

MemberAddArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MemberAddArg::toJson(QJsonObject& js)const{

    if(!m_member_email.isEmpty())
        js["member_email"] = QString(m_member_email);
    if(!m_member_given_name.isEmpty())
        js["member_given_name"] = QString(m_member_given_name);
    if(!m_member_surname.isEmpty())
        js["member_surname"] = QString(m_member_surname);
    if(!m_member_external_id.isEmpty())
        js["member_external_id"] = QString(m_member_external_id);
    js["send_welcome_email"] = m_send_welcome_email;
    m_role.toJson(js, "role");
}

void MemberAddArg::fromJson(const QJsonObject& js){

    m_member_email = js["member_email"].toString();
    m_member_given_name = js["member_given_name"].toString();
    m_member_surname = js["member_surname"].toString();
    m_member_external_id = js["member_external_id"].toString();
    m_send_welcome_email = js["send_welcome_email"].toVariant().toBool();
    m_role.fromJson(js["role"].toObject());
}

QString MemberAddArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MemberAddArg>  MemberAddArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MemberAddArg>  MemberAddArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MemberAddArg> rv;
    rv = std::unique_ptr<MemberAddArg>(new MemberAddArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
