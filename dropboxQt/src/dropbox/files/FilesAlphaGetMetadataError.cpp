/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesAlphaGetMetadataError.h"

namespace dropboxQt{

namespace files{
///AlphaGetMetadataError

AlphaGetMetadataError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AlphaGetMetadataError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetMetadataError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case AlphaGetMetadataError_PROPERTIES_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("properties_error");
            m_properties_error.toJson(js, "properties_error");
        }break;
    }//switch
}

void AlphaGetMetadataError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = GetMetadataError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    if(s.compare("properties_error") == 0){
        m_tag = AlphaGetMetadataError_PROPERTIES_ERROR;
        m_properties_error.fromJson(js["properties_error"].toObject());
    }
}

QString AlphaGetMetadataError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AlphaGetMetadataError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AlphaGetMetadataError>  AlphaGetMetadataError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AlphaGetMetadataError> rv = std::unique_ptr<AlphaGetMetadataError>(new AlphaGetMetadataError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
