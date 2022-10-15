/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionFinishBatchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///UploadSessionFinishBatchArg

UploadSessionFinishBatchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UploadSessionFinishBatchArg::toJson(QJsonObject& js)const{

    js["entries"] = struct_list2jsonarray(m_entries);
}

void UploadSessionFinishBatchArg::fromJson(const QJsonObject& js){

    jsonarray2struct_list(js["entries"].toArray(), m_entries);
}

QString UploadSessionFinishBatchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UploadSessionFinishBatchArg>  UploadSessionFinishBatchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UploadSessionFinishBatchArg>  UploadSessionFinishBatchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UploadSessionFinishBatchArg> rv;
    rv = std::unique_ptr<UploadSessionFinishBatchArg>(new UploadSessionFinishBatchArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
