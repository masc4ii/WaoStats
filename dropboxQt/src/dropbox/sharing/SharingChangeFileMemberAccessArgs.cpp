/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingChangeFileMemberAccessArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ChangeFileMemberAccessArgs

ChangeFileMemberAccessArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ChangeFileMemberAccessArgs::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    m_member.toJson(js, "member");
    m_access_level.toJson(js, "access_level");
}

void ChangeFileMemberAccessArgs::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    m_member.fromJson(js["member"].toObject());
    m_access_level.fromJson(js["access_level"].toObject());
}

QString ChangeFileMemberAccessArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ChangeFileMemberAccessArgs>  ChangeFileMemberAccessArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ChangeFileMemberAccessArgs>  ChangeFileMemberAccessArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ChangeFileMemberAccessArgs> rv;
    rv = std::unique_ptr<ChangeFileMemberAccessArgs>(new ChangeFileMemberAccessArgs);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
