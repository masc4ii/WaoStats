/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetFileMetadataIndividualResult.h"

namespace dropboxQt{

namespace sharing{
///GetFileMetadataIndividualResult

GetFileMetadataIndividualResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetFileMetadataIndividualResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetFileMetadataIndividualResult_METADATA:{
            if(!name.isEmpty())
                js[name] = QString("metadata");
            js["metadata"] = (QJsonObject)m_metadata;
        }break;
        case GetFileMetadataIndividualResult_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case GetFileMetadataIndividualResult_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetFileMetadataIndividualResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("metadata") == 0){
        m_tag = GetFileMetadataIndividualResult_METADATA;
        m_metadata.fromJson(js["metadata"].toObject());
    }
    else if(s.compare("access_error") == 0){
        m_tag = GetFileMetadataIndividualResult_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = GetFileMetadataIndividualResult_OTHER;

    }
}

QString GetFileMetadataIndividualResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetFileMetadataIndividualResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetFileMetadataIndividualResult>  GetFileMetadataIndividualResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetFileMetadataIndividualResult> rv = std::unique_ptr<GetFileMetadataIndividualResult>(new GetFileMetadataIndividualResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
