/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesRelocationArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///RelocationArg

RelocationArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void RelocationArg::toJson(QJsonObject& js)const{

    if(!m_from_path.isEmpty())
        js["from_path"] = QString(m_from_path);
    if(!m_to_path.isEmpty())
        js["to_path"] = QString(m_to_path);
}

void RelocationArg::fromJson(const QJsonObject& js){

    m_from_path = js["from_path"].toString();
    m_to_path = js["to_path"].toString();
}

QString RelocationArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<RelocationArg>  RelocationArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<RelocationArg>  RelocationArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<RelocationArg> rv;
    rv = std::unique_ptr<RelocationArg>(new RelocationArg);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
