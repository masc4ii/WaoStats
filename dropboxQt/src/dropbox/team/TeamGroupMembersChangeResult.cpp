/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMembersChangeResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///GroupMembersChangeResult

GroupMembersChangeResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GroupMembersChangeResult::toJson(QJsonObject& js)const{

    js["group_info"] = (QJsonObject)m_group_info;
    if(!m_async_job_id.isEmpty())
        js["async_job_id"] = QString(m_async_job_id);
}

void GroupMembersChangeResult::fromJson(const QJsonObject& js){

    m_group_info.fromJson(js["group_info"].toObject());
    m_async_job_id = js["async_job_id"].toString();
}

QString GroupMembersChangeResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GroupMembersChangeResult>  GroupMembersChangeResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GroupMembersChangeResult>  GroupMembersChangeResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GroupMembersChangeResult> rv;
    rv = std::unique_ptr<GroupMembersChangeResult>(new GroupMembersChangeResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
