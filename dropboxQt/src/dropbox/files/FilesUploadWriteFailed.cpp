/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadWriteFailed.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///UploadWriteFailed

UploadWriteFailed::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UploadWriteFailed::toJson(QJsonObject& js)const{

    m_reason.toJson(js, "reason");
    if(!m_upload_session_id.isEmpty())
        js["upload_session_id"] = QString(m_upload_session_id);
}

void UploadWriteFailed::fromJson(const QJsonObject& js){

    m_reason.fromJson(js["reason"].toObject());
    m_upload_session_id = js["upload_session_id"].toString();
}

QString UploadWriteFailed::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UploadWriteFailed>  UploadWriteFailed::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UploadWriteFailed>  UploadWriteFailed::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UploadWriteFailed> rv;
    rv = std::unique_ptr<UploadWriteFailed>(new UploadWriteFailed);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
