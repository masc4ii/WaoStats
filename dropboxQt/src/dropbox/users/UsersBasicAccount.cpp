/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersBasicAccount.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///BasicAccount

BasicAccount::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void BasicAccount::toJson(QJsonObject& js)const{

    Account::toJson(js);
    js["is_teammate"] = m_is_teammate;
    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
}

void BasicAccount::fromJson(const QJsonObject& js){

    Account::fromJson(js);
    m_is_teammate = js["is_teammate"].toVariant().toBool();
    m_team_member_id = js["team_member_id"].toString();
}

QString BasicAccount::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<BasicAccount>  BasicAccount::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<BasicAccount>  BasicAccount::factory::create(const QJsonObject& js)
{
    std::unique_ptr<BasicAccount> rv;
    rv = std::unique_ptr<BasicAccount>(new BasicAccount);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
