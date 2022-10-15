/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFilesArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFilesArg

ListFilesArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFilesArg::toJson(QJsonObject& js)const{

    js["limit"] = QString("%1").arg(m_limit);
    js["actions"] = struct_list2jsonarray(m_actions);
}

void ListFilesArg::fromJson(const QJsonObject& js){

    m_limit = js["limit"].toVariant().toString().toULongLong();
    jsonarray2struct_list(js["actions"].toArray(), m_actions);
}

QString ListFilesArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFilesArg>  ListFilesArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFilesArg>  ListFilesArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFilesArg> rv;
    rv = std::unique_ptr<ListFilesArg>(new ListFilesArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
