/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersGetInfoArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersGetInfoArgs

MembersGetInfoArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersGetInfoArgs::toJson(QJsonObject& js)const{

    js["members"] = struct_list2jsonarray(m_members);
}

void MembersGetInfoArgs::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["members"].toArray(), m_members);
}

QString MembersGetInfoArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersGetInfoArgs>  MembersGetInfoArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersGetInfoArgs>  MembersGetInfoArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersGetInfoArgs> rv;
    rv = std::unique_ptr<MembersGetInfoArgs>(new MembersGetInfoArgs);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
