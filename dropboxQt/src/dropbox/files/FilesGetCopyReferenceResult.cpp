/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesGetCopyReferenceResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///GetCopyReferenceResult

GetCopyReferenceResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetCopyReferenceResult::toJson(QJsonObject& js)const{

    js["metadata"] = (QJsonObject)m_metadata;
    if(!m_copy_reference.isEmpty())
        js["copy_reference"] = QString(m_copy_reference);
    if(m_expires.isValid())
        js["expires"] = m_expires.toString("yyyy-MM-ddThh:mm:ssZ");
}

void GetCopyReferenceResult::fromJson(const QJsonObject& js){

    m_metadata.fromJson(js["metadata"].toObject());
    m_copy_reference = js["copy_reference"].toString();
    m_expires = QDateTime::fromString(js["expires"].toString(), "yyyy-MM-ddThh:mm:ssZ");
}

QString GetCopyReferenceResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetCopyReferenceResult>  GetCopyReferenceResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetCopyReferenceResult>  GetCopyReferenceResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetCopyReferenceResult> rv;
    rv = std::unique_ptr<GetCopyReferenceResult>(new GetCopyReferenceResult);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
