/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadError.h"

namespace dropboxQt{

namespace files{
///UploadError

UploadError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadError::toJson(QJsonObject& js, QString name)const{

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
    }//switch
}

void UploadError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = UploadError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = UploadError_OTHER;

    }
}

QString UploadError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UploadError>  UploadError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UploadError> rv = std::unique_ptr<UploadError>(new UploadError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
