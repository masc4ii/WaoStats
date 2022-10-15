/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetFileMetadataArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetFileMetadataArg

GetFileMetadataArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetFileMetadataArg::toJson(QJsonObject& js)const{

    if(!m_file.isEmpty())
        js["file"] = QString(m_file);
    js["actions"] = struct_list2jsonarray(m_actions);
}

void GetFileMetadataArg::fromJson(const QJsonObject& js){

    m_file = js["file"].toString();
    jsonarray2struct_list(js["actions"].toArray(), m_actions);
}

QString GetFileMetadataArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetFileMetadataArg>  GetFileMetadataArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetFileMetadataArg>  GetFileMetadataArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetFileMetadataArg> rv;
    rv = std::unique_ptr<GetFileMetadataArg>(new GetFileMetadataArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
