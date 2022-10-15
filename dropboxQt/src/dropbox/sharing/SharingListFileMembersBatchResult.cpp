/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFileMembersBatchResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///ListFileMembersBatchResult

ListFileMembersBatchResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ListFileMembersBatchResult::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    m_result.toJson(js, "result");
}

void ListFileMembersBatchResult::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    m_result.fromJson(js["result"].toObject());
}

QString ListFileMembersBatchResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ListFileMembersBatchResult>  ListFileMembersBatchResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ListFileMembersBatchResult>  ListFileMembersBatchResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ListFileMembersBatchResult> rv;
    rv = std::unique_ptr<ListFileMembersBatchResult>(new ListFileMembersBatchResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
