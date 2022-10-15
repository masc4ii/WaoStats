/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAddFolderMemberArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///AddFolderMemberArg

AddFolderMemberArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void AddFolderMemberArg::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["members"] = struct_list2jsonarray(m_members);
    js["quiet"] = m_quiet;
    if(!m_custom_message.isEmpty())
        js["custom_message"] = QString(m_custom_message);
}

void AddFolderMemberArg::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
    jsonarray2struct_list(js["members"].toArray(), m_members);
    m_quiet = js["quiet"].toVariant().toBool();
    m_custom_message = js["custom_message"].toString();
}

QString AddFolderMemberArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<AddFolderMemberArg>  AddFolderMemberArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<AddFolderMemberArg>  AddFolderMemberArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<AddFolderMemberArg> rv;
    rv = std::unique_ptr<AddFolderMemberArg>(new AddFolderMemberArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
