/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetFileMetadataBatchResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetFileMetadataBatchResult

GetFileMetadataBatchResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetFileMetadataBatchResult::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    m_result.toJson(js, "result");
}

void GetFileMetadataBatchResult::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    m_result.fromJson(js["result"].toObject());
}

QString GetFileMetadataBatchResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetFileMetadataBatchResult>  GetFileMetadataBatchResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetFileMetadataBatchResult>  GetFileMetadataBatchResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetFileMetadataBatchResult> rv;
    rv = std::unique_ptr<GetFileMetadataBatchResult>(new GetFileMetadataBatchResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
