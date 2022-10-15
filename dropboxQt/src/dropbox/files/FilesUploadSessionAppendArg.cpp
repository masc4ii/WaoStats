/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionAppendArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///UploadSessionAppendArg

UploadSessionAppendArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UploadSessionAppendArg::toJson(QJsonObject& js)const{

    js["cursor"] = (QJsonObject)m_cursor;
    js["close"] = m_close;
}

void UploadSessionAppendArg::fromJson(const QJsonObject& js){

    m_cursor.fromJson(js["cursor"].toObject());
    m_close = js["close"].toVariant().toBool();
}

QString UploadSessionAppendArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UploadSessionAppendArg>  UploadSessionAppendArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UploadSessionAppendArg>  UploadSessionAppendArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UploadSessionAppendArg> rv;
    rv = std::unique_ptr<UploadSessionAppendArg>(new UploadSessionAppendArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
