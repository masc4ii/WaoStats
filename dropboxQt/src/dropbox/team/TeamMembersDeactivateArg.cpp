/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersDeactivateArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///MembersDeactivateArg

MembersDeactivateArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void MembersDeactivateArg::toJson(QJsonObject& js)const{

    m_user.toJson(js, "user");
    js["wipe_data"] = m_wipe_data;
}

void MembersDeactivateArg::fromJson(const QJsonObject& js){

    m_user.fromJson(js["user"].toObject());
    m_wipe_data = js["wipe_data"].toVariant().toBool();
}

QString MembersDeactivateArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<MembersDeactivateArg>  MembersDeactivateArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<MembersDeactivateArg>  MembersDeactivateArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<MembersDeactivateArg> rv;
    rv = std::unique_ptr<MembersDeactivateArg>(new MembersDeactivateArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
