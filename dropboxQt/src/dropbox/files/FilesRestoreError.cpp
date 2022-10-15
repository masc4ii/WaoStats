/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesRestoreError.h"

namespace dropboxQt{

namespace files{
///RestoreError

RestoreError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RestoreError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RestoreError_PATH_LOOKUP:{
            if(!name.isEmpty())
                js[name] = QString("path_lookup");
            m_path_lookup.toJson(js, "path_lookup");
        }break;
        case RestoreError_PATH_WRITE:{
            if(!name.isEmpty())
                js[name] = QString("path_write");
            m_path_write.toJson(js, "path_write");
        }break;
        case RestoreError_INVALID_REVISION:{
            if(!name.isEmpty())
                js[name] = QString("invalid_revision");
        }break;
        case RestoreError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RestoreError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path_lookup") == 0){
        m_tag = RestoreError_PATH_LOOKUP;
        m_path_lookup.fromJson(js["path_lookup"].toObject());
    }
    else if(s.compare("path_write") == 0){
        m_tag = RestoreError_PATH_WRITE;
        m_path_write.fromJson(js["path_write"].toObject());
    }
    else if(s.compare("invalid_revision") == 0){
        m_tag = RestoreError_INVALID_REVISION;

    }
    else if(s.compare("other") == 0){
        m_tag = RestoreError_OTHER;

    }
}

QString RestoreError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RestoreError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RestoreError>  RestoreError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RestoreError> rv = std::unique_ptr<RestoreError>(new RestoreError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
