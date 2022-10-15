/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSaveUrlArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///SaveUrlArg

SaveUrlArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SaveUrlArg::toJson(QJsonObject& js)const{

    if(!m_path.isEmpty())
        js["path"] = QString(m_path);
    if(!m_url.isEmpty())
        js["url"] = QString(m_url);
}

void SaveUrlArg::fromJson(const QJsonObject& js){

    m_path = js["path"].toString();
    m_url = js["url"].toString();
}

QString SaveUrlArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SaveUrlArg>  SaveUrlArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SaveUrlArg>  SaveUrlArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SaveUrlArg> rv;
    rv = std::unique_ptr<SaveUrlArg>(new SaveUrlArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
