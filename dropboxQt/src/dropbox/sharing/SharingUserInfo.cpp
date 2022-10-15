/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUserInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///UserInfo

UserInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UserInfo::toJson(QJsonObject& js)const{

    if(!m_account_id.isEmpty())
        js["account_id"] = QString(m_account_id);
    js["same_team"] = m_same_team;
    if(!m_team_member_id.isEmpty())
        js["team_member_id"] = QString(m_team_member_id);
}

void UserInfo::fromJson(const QJsonObject& js){

    m_account_id = js["account_id"].toString();
    m_same_team = js["same_team"].toVariant().toBool();
    m_team_member_id = js["team_member_id"].toString();
}

QString UserInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UserInfo>  UserInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UserInfo>  UserInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UserInfo> rv;
    rv = std::unique_ptr<UserInfo>(new UserInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
