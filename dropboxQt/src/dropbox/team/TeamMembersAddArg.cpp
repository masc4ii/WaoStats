/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersAddArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersAddArg

MembersAddArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersAddArg::toJson(QJsonObject& js)const{

    js["new_members"] = struct_list2jsonarray(m_new_members);
    js["force_async"] = m_force_async;
}

void MembersAddArg::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["new_members"].toArray(), m_new_members);
    m_force_async = js["force_async"].toVariant().toBool();
}

QString MembersAddArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersAddArg>  MembersAddArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersAddArg>  MembersAddArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersAddArg> rv;
    rv = std::unique_ptr<MembersAddArg>(new MembersAddArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
