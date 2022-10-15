/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionStartArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///UploadSessionStartArg

UploadSessionStartArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UploadSessionStartArg::toJson(QJsonObject& js)const{

    js["close"] = m_close;
}

void UploadSessionStartArg::fromJson(const QJsonObject& js){

    m_close = js["close"].toVariant().toBool();
}

QString UploadSessionStartArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UploadSessionStartArg>  UploadSessionStartArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UploadSessionStartArg>  UploadSessionStartArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UploadSessionStartArg> rv;
    rv = std::unique_ptr<UploadSessionStartArg>(new UploadSessionStartArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
