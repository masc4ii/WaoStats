/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMembersDevicesResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///ListMembersDevicesResult

ListMembersDevicesResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListMembersDevicesResult::toJson(QJsonObject& js)const{

    js["devices"] = struct_list2jsonarray(m_devices);
    js["has_more"] = m_has_more;
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void ListMembersDevicesResult::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["devices"].toArray(), m_devices);
    m_has_more = js["has_more"].toVariant().toBool();
    m_cursor = js["cursor"].toString();
}

QString ListMembersDevicesResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListMembersDevicesResult>  ListMembersDevicesResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListMembersDevicesResult>  ListMembersDevicesResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListMembersDevicesResult> rv;
    rv = std::unique_ptr<ListMembersDevicesResult>(new ListMembersDevicesResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
