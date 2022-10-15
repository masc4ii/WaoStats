/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedFileMembers.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///SharedFileMembers

SharedFileMembers::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SharedFileMembers::toJson(QJsonObject& js)const{

    js["users"] = struct_list2jsonarray(m_users);
    js["groups"] = struct_list2jsonarray(m_groups);
    js["invitees"] = struct_list2jsonarray(m_invitees);
    if(!m_cursor.isEmpty())
        js["cursor"] = QString(m_cursor);
}

void SharedFileMembers::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["users"].toArray(), m_users);
    jsonarray2struct_list(js["groups"].toArray(), m_groups);
    jsonarray2struct_list(js["invitees"].toArray(), m_invitees);
    m_cursor = js["cursor"].toString();
}

QString SharedFileMembers::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SharedFileMembers>  SharedFileMembers::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SharedFileMembers>  SharedFileMembers::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SharedFileMembers> rv;
    rv = std::unique_ptr<SharedFileMembers>(new SharedFileMembers);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
