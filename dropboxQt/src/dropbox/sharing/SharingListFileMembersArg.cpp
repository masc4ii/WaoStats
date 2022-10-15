/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFileMembersArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFileMembersArg

ListFileMembersArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFileMembersArg::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    js["actions"] = struct_list2jsonarray(m_actions);
    js["include_inherited"] = m_include_inherited;
    js["limit"] = QString("%1").arg(m_limit);
}

void ListFileMembersArg::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    jsonarray2struct_list(js["actions"].toArray(), m_actions);
    m_include_inherited = js["include_inherited"].toVariant().toBool();
    m_limit = js["limit"].toVariant().toString().toULongLong();
}

QString ListFileMembersArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFileMembersArg>  ListFileMembersArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFileMembersArg>  ListFileMembersArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFileMembersArg> rv;
    rv = std::unique_ptr<ListFileMembersArg>(new ListFileMembersArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
