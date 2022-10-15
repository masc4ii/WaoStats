/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetFileMetadataBatchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace sharing{
///GetFileMetadataBatchArg

GetFileMetadataBatchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetFileMetadataBatchArg::toJson(QJsonObject& js)const{

    js["files"] = ingrl_list2jsonarray(m_files);
    js["actions"] = struct_list2jsonarray(m_actions);
}

void GetFileMetadataBatchArg::fromJson(const QJsonObject& js){

    jsonarray2ingrl_list(js["files"].toArray(), m_files);
    jsonarray2struct_list(js["actions"].toArray(), m_actions);
}

QString GetFileMetadataBatchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetFileMetadataBatchArg>  GetFileMetadataBatchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetFileMetadataBatchArg>  GetFileMetadataBatchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetFileMetadataBatchArg> rv;
    rv = std::unique_ptr<GetFileMetadataBatchArg>(new GetFileMetadataBatchArg);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
