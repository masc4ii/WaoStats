/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesGetTemporaryLinkArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///GetTemporaryLinkArg

GetTemporaryLinkArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetTemporaryLinkArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
}

void GetTemporaryLinkArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
}

QString GetTemporaryLinkArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetTemporaryLinkArg>  GetTemporaryLinkArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetTemporaryLinkArg>  GetTemporaryLinkArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetTemporaryLinkArg> rv;
    rv = std::unique_ptr<GetTemporaryLinkArg>(new GetTemporaryLinkArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
