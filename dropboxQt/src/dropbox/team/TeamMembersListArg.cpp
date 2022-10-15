/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersListArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersListArg

MembersListArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersListArg::toJson(QJsonObject& js)const{

    js["limit"] = QString("%1").arg(m_limit);
    js["include_removed"] = m_include_removed;
}

void MembersListArg::fromJson(const QJsonObject& js){

    m_limit = js["limit"].toVariant().toString().toULongLong();
    m_include_removed = js["include_removed"].toVariant().toBool();
}

QString MembersListArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersListArg>  MembersListArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersListArg>  MembersListArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersListArg> rv;
    rv = std::unique_ptr<MembersListArg>(new MembersListArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
