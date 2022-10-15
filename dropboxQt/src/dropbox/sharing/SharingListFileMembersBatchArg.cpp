/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFileMembersBatchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFileMembersBatchArg

ListFileMembersBatchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFileMembersBatchArg::toJson(QJsonObject& js)const{

    js["files"] = ingrl_list2jsonarray(m_files);
    js["limit"] = QString("%1").arg(m_limit);
}

void ListFileMembersBatchArg::fromJson(const QJsonObject& js){

    jsonarray2ingrl_list(js["files"].toArray(), m_files);
    m_limit = js["limit"].toVariant().toString().toULongLong();
}

QString ListFileMembersBatchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFileMembersBatchArg>  ListFileMembersBatchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFileMembersBatchArg>  ListFileMembersBatchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFileMembersBatchArg> rv;
    rv = std::unique_ptr<ListFileMembersBatchArg>(new ListFileMembersBatchArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
