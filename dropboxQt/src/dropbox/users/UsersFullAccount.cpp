/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersFullAccount.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///FullAccount

FullAccount::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void FullAccount::toJson(QJsonObject& js)const{

    Account::toJson(js);
    if(!m_country.isEmpty())
        js["country"] = QString(m_country);
    if(!m_locale.isEmpty())
        js["locale"] = QString(m_locale);
    if(!m_referral_link.isEmpty())
        js["referral_link"] = QString(m_referral_link);
    js["team"] = (QJsonObject)m_team;
    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
    js["is_paired"] = m_is_paired;
    m_account_type.toJson(js, "account_type");
}

void FullAccount::fromJson(const QJsonObject& js){

    Account::fromJson(js);
    m_country = js["country"].toString();
    m_locale = js["locale"].toString();
    m_referral_link = js["referral_link"].toString();
    m_team.fromJson(js["team"].toObject());
    m_team_member_id = js["team_member_id"].toString();
    m_is_paired = js["is_paired"].toVariant().toBool();
    m_account_type.fromJson(js["account_type"].toObject());
}

QString FullAccount::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<FullAccount>  FullAccount::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<FullAccount>  FullAccount::factory::create(const QJsonObject& js)
{
    std::unique_ptr<FullAccount> rv;
    rv = std::unique_ptr<FullAccount>(new FullAccount);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
