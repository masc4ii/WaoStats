/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDesktopClientArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace team{
///RevokeDesktopClientArg

RevokeDesktopClientArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RevokeDesktopClientArg::toJson(QJsonObject& js)const{

    DeviceSessionArg::toJson(js);
    js["delete_on_unlink"] = m_delete_on_unlink;
}

void RevokeDesktopClientArg::fromJson(const QJsonObject& js){

    DeviceSessionArg::fromJson(js);
    m_delete_on_unlink = js["delete_on_unlink"].toVariant().toBool();
}

QString RevokeDesktopClientArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RevokeDesktopClientArg>  RevokeDesktopClientArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RevokeDesktopClientArg>  RevokeDesktopClientArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RevokeDesktopClientArg> rv;
    rv = std::unique_ptr<RevokeDesktopClientArg>(new RevokeDesktopClientArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
