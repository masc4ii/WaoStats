/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_common"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team_common/TeamCommonGroupSummary.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team_common{
///GroupSummary

GroupSummary::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupSummary::toJson(QJsonObject& js)const{

    if(!m_group_name.isEmpty())
        js["group_name"] = QString(m_group_name);
    if(!m_group_id.isEmpty())
        js["group_id"] = QString(m_group_id);
    if(!m_group_external_id.isEmpty())
        js["group_external_id"] = QString(m_group_external_id);
    js["member_count"] = QString("%1").arg(m_member_count);
    m_group_management_type.toJson(js, "group_management_type");
}

void GroupSummary::fromJson(const QJsonObject& js){

    m_group_name = js["group_name"].toString();
    m_group_id = js["group_id"].toString();
    m_group_external_id = js["group_external_id"].toString();
    m_member_count = js["member_count"].toVariant().toString().toULongLong();
    m_group_management_type.fromJson(js["group_management_type"].toObject());
}

QString GroupSummary::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupSummary>  GroupSummary::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupSummary>  GroupSummary::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupSummary> rv;
    rv = std::unique_ptr<GroupSummary>(new GroupSummary);
    rv->fromJson(js);
    return rv;
}

}//team_common
}//dropboxQt
