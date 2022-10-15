/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamIncludeMembersArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///IncludeMembersArg

IncludeMembersArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void IncludeMembersArg::toJson(QJsonObject& js)const{

    js["return_members"] = m_return_members;
}

void IncludeMembersArg::fromJson(const QJsonObject& js){

    m_return_members = js["return_members"].toVariant().toBool();
}

QString IncludeMembersArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<IncludeMembersArg>  IncludeMembersArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<IncludeMembersArg>  IncludeMembersArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<IncludeMembersArg> rv;
    rv = std::unique_ptr<IncludeMembersArg>(new IncludeMembersArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
