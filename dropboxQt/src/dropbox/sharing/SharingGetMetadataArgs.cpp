/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetMetadataArgs.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetMetadataArgs

GetMetadataArgs::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetMetadataArgs::toJson(QJsonObject& js)const{

    if(!m_shared_folder_id.isEmpty())
        js["shared_folder_id"] = QString(m_shared_folder_id);
    js["actions"] = struct_list2jsonarray(m_actions);
}

void GetMetadataArgs::fromJson(const QJsonObject& js){

    m_shared_folder_id = js["shared_folder_id"].toString();
    jsonarray2struct_list(js["actions"].toArray(), m_actions);
}

QString GetMetadataArgs::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetMetadataArgs>  GetMetadataArgs::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetMetadataArgs>  GetMetadataArgs::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetMetadataArgs> rv;
    rv = std::unique_ptr<GetMetadataArgs>(new GetMetadataArgs);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
