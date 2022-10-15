/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAddFileMemberArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///AddFileMemberArgs

AddFileMemberArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void AddFileMemberArgs::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    js["members"] = struct_list2jsonarray(m_members);
    if(!m_custom_message.isEmpty())
        js["custom_message"] = QString(m_custom_message);
    js["quiet"] = m_quiet;
    m_access_level.toJson(js, "access_level");
    js["add_message_as_comment"] = m_add_message_as_comment;
}

void AddFileMemberArgs::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    jsonarray2struct_list(js["members"].toArray(), m_members);
    m_custom_message = js["custom_message"].toString();
    m_quiet = js["quiet"].toVariant().toBool();
    m_access_level.fromJson(js["access_level"].toObject());
    m_add_message_as_comment = js["add_message_as_comment"].toVariant().toBool();
}

QString AddFileMemberArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<AddFileMemberArgs>  AddFileMemberArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<AddFileMemberArgs>  AddFileMemberArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<AddFileMemberArgs> rv;
    rv = std::unique_ptr<AddFileMemberArgs>(new AddFileMemberArgs);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
