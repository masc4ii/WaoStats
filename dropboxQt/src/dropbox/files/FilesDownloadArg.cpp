/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesDownloadArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///DownloadArg

DownloadArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void DownloadArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    if(!m_rev.isEmpty())
        js["rev"] = QString(m_rev);
}

void DownloadArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_rev = js["rev"].toString();
}

QString DownloadArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<DownloadArg>  DownloadArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<DownloadArg>  DownloadArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<DownloadArg> rv;
    rv = std::unique_ptr<DownloadArg>(new DownloadArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
