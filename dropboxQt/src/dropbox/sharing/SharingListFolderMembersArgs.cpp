/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFolderMembersArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFolderMembersArgs

ListFolderMembersArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFolderMembersArgs::toJson(QJsonObject& js)const{

    ListFolderMembersCursorArg::toJson(js);
    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
}

void ListFolderMembersArgs::fromJson(const QJsonObject& js){

    ListFolderMembersCursorArg::fromJson(js);
    m_shared_folder_id = js["shared_folder_id"].toString();
}

QString ListFolderMembersArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFolderMembersArgs>  ListFolderMembersArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFolderMembersArgs>  ListFolderMembersArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFolderMembersArgs> rv;
    rv = std::unique_ptr<ListFolderMembersArgs>(new ListFolderMembersArgs);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
