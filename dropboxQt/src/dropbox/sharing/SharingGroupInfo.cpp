/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGroupInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GroupInfo

GroupInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupInfo::toJson(QJsonObject& js)const{

    GroupSummary::toJson(js);
    m_group_type.toJson(js, "group_type");
    js["is_owner"] = m_is_owner;
    js["same_team"] = m_same_team;
}

void GroupInfo::fromJson(const QJsonObject& js){

    GroupSummary::fromJson(js);
    m_group_type.fromJson(js["group_type"].toObject());
    m_is_owner = js["is_owner"].toVariant().toBool();
    m_same_team = js["same_team"].toVariant().toBool();
}

QString GroupInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupInfo>  GroupInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupInfo>  GroupInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupInfo> rv;
    rv = std::unique_ptr<GroupInfo>(new GroupInfo);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
