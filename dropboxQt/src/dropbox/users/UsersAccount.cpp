/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersAccount.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///Account

Account::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void Account::toJson(QJsonObject& js)const{

    if(!m_account_id.isEmpty())
        js["account_id"] = QString(m_account_id);
    js["name"] = (QJsonObject)m_name;
    if(!m_email.isEmpty())
        js["email"] = QString(m_email);
    js["email_verified"] = m_email_verified;
    if(!m_profile_photo_url.isEmpty())
        js["profile_photo_url"] = QString(m_profile_photo_url);
    js["disabled"] = m_disabled;
}

void Account::fromJson(const QJsonObject& js){

    m_account_id = js["account_id"].toString();
    m_name.fromJson(js["name"].toObject());
    m_email = js["email"].toString();
    m_email_verified = js["email_verified"].toVariant().toBool();
    m_profile_photo_url = js["profile_photo_url"].toString();
    m_disabled = js["disabled"].toVariant().toBool();
}

QString Account::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<Account>  Account::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<Account>  Account::factory::create(const QJsonObject& js)
{
    std::unique_ptr<Account> rv;
    rv = std::unique_ptr<Account>(new Account);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
