/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRemoveFolderMemberArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///RemoveFolderMemberArg

RemoveFolderMemberArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RemoveFolderMemberArg::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    m_member.toJson(js, "member");
    js["leave_a_copy"] = m_leave_a_copy;
}

void RemoveFolderMemberArg::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
    m_member.fromJson(js["member"].toObject());
    m_leave_a_copy = js["leave_a_copy"].toVariant().toBool();
}

QString RemoveFolderMemberArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RemoveFolderMemberArg>  RemoveFolderMemberArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RemoveFolderMemberArg>  RemoveFolderMemberArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RemoveFolderMemberArg> rv;
    rv = std::unique_ptr<RemoveFolderMemberArg>(new RemoveFolderMemberArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
