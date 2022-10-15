/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUpdateFolderMemberArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///UpdateFolderMemberArg

UpdateFolderMemberArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UpdateFolderMemberArg::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    m_member.toJson(js, "member");
    m_access_level.toJson(js, "access_level");
}

void UpdateFolderMemberArg::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
    m_member.fromJson(js["member"].toObject());
    m_access_level.fromJson(js["access_level"].toObject());
}

QString UpdateFolderMemberArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UpdateFolderMemberArg>  UpdateFolderMemberArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UpdateFolderMemberArg>  UpdateFolderMemberArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UpdateFolderMemberArg> rv;
    rv = std::unique_ptr<UpdateFolderMemberArg>(new UpdateFolderMemberArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
