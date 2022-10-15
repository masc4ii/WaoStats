/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersUnsuspendArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersUnsuspendArg

MembersUnsuspendArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersUnsuspendArg::toJson(QJsonObject& js)const{

    m_user.toJson(js, "user");
}

void MembersUnsuspendArg::fromJson(const QJsonObject& js){

    m_user.fromJson(js["user"].toObject());
}

QString MembersUnsuspendArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersUnsuspendArg>  MembersUnsuspendArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersUnsuspendArg>  MembersUnsuspendArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersUnsuspendArg> rv;
    rv = std::unique_ptr<MembersUnsuspendArg>(new MembersUnsuspendArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
