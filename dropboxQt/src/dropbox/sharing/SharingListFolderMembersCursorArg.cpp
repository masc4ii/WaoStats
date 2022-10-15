/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFolderMembersCursorArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFolderMembersCursorArg

ListFolderMembersCursorArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFolderMembersCursorArg::toJson(QJsonObject& js)const{

    js["actions"] = struct_list2jsonarray(m_actions);
    js["limit"] = QString("%1").arg(m_limit);
}

void ListFolderMembersCursorArg::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["actions"].toArray(), m_actions);
    m_limit = js["limit"].toVariant().toString().toULongLong();
}

QString ListFolderMembersCursorArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFolderMembersCursorArg>  ListFolderMembersCursorArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFolderMembersCursorArg>  ListFolderMembersCursorArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFolderMembersCursorArg> rv;
    rv = std::unique_ptr<ListFolderMembersCursorArg>(new ListFolderMembersCursorArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
