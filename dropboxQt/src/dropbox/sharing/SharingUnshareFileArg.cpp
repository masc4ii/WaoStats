/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUnshareFileArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///UnshareFileArg

UnshareFileArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void UnshareFileArg::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
}

void UnshareFileArg::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
}

QString UnshareFileArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<UnshareFileArg>  UnshareFileArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<UnshareFileArg>  UnshareFileArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<UnshareFileArg> rv;
    rv = std::unique_ptr<UnshareFileArg>(new UnshareFileArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
