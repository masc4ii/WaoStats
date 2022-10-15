/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSaveCopyReferenceResult.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///SaveCopyReferenceResult

SaveCopyReferenceResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SaveCopyReferenceResult::toJson(QJsonObject& js)const{

    js["metadata"] = (QJsonObject)m_metadata;
}

void SaveCopyReferenceResult::fromJson(const QJsonObject& js){

    m_metadata.fromJson(js["metadata"].toObject());
}

QString SaveCopyReferenceResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SaveCopyReferenceResult>  SaveCopyReferenceResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SaveCopyReferenceResult>  SaveCopyReferenceResult::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SaveCopyReferenceResult> rv;
    rv = std::unique_ptr<SaveCopyReferenceResult>(new SaveCopyReferenceResult);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
