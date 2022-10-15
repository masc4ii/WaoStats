/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRemoveFileMemberArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///RemoveFileMemberArg

RemoveFileMemberArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RemoveFileMemberArg::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    m_member.toJson(js, "member");
}

void RemoveFileMemberArg::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    m_member.fromJson(js["member"].toObject());
}

QString RemoveFileMemberArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RemoveFileMemberArg>  RemoveFileMemberArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RemoveFileMemberArg>  RemoveFileMemberArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RemoveFileMemberArg> rv;
    rv = std::unique_ptr<RemoveFileMemberArg>(new RemoveFileMemberArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
