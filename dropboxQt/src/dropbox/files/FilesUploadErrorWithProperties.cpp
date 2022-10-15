/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadErrorWithProperties.h"

namespace dropboxQt{

namespace files{
///UploadErrorWithProperties

UploadErrorWithProperties::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadErrorWithProperties::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UploadError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            js["path"] = (QJsonObject)m_path;
        }break;
        case UploadError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case UploadErrorWithProperties_PROPERTIES_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("properties_error");
            m_properties_error.toJson(js, "properties_error");
        }break;
    }//switch
}

void UploadErrorWithProperties::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = UploadError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = UploadError_OTHER;

    }
    if(s.compare("properties_error") == 0){
        m_tag = UploadErrorWithProperties_PROPERTIES_ERROR;
        m_properties_error.fromJson(js["properties_error"].toObject());
    }
}

QString UploadErrorWithProperties::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadErrorWithProperties");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UploadErrorWithProperties>  UploadErrorWithProperties::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UploadErrorWithProperties> rv = std::unique_ptr<UploadErrorWithProperties>(new UploadErrorWithProperties);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
