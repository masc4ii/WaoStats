/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSharingInfo.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace files{
///SharingInfo

SharingInfo::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void SharingInfo::toJson(QJsonObject& js)const{

    js["read_only"] = m_read_only;
}

void SharingInfo::fromJson(const QJsonObject& js){

    m_read_only = js["read_only"].toVariant().toBool();
}

QString SharingInfo::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<SharingInfo>  SharingInfo::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<SharingInfo>  SharingInfo::factory::create(const QJsonObject& js)
{
    std::unique_ptr<SharingInfo> rv;
    rv = std::unique_ptr<SharingInfo>(new SharingInfo);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
