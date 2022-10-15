/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFileMembersCountResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFileMembersCountResult

ListFileMembersCountResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFileMembersCountResult::toJson(QJsonObject& js)const{

    js["members"] = (QJsonObject)m_members;
    js["member_count"] = QString("%1").arg(m_member_count);
}

void ListFileMembersCountResult::fromJson(const QJsonObject& js){

    m_members.fromJson(js["members"].toObject());
    m_member_count = js["member_count"].toVariant().toString().toULongLong();
}

QString ListFileMembersCountResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFileMembersCountResult>  ListFileMembersCountResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFileMembersCountResult>  ListFileMembersCountResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFileMembersCountResult> rv;
    rv = std::unique_ptr<ListFileMembersCountResult>(new ListFileMembersCountResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
