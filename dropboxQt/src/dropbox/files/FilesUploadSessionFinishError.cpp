/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionFinishError.h"

namespace dropboxQt{

namespace files{
///UploadSessionFinishError

UploadSessionFinishError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadSessionFinishError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UploadSessionFinishError_LOOKUP_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("lookup_failed");
            m_lookup_failed.toJson(js, "lookup_failed");
        }break;
        case UploadSessionFinishError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case UploadSessionFinishError_TOO_MANY_SHARED_FOLDER_TARGETS:{
            if(!name.isEmpty())
                js[name] = QString("too_many_shared_folder_targets");
        }break;
        case UploadSessionFinishError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void UploadSessionFinishError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("lookup_failed") == 0){
        m_tag = UploadSessionFinishError_LOOKUP_FAILED;
        m_lookup_failed.fromJson(js["lookup_failed"].toObject());
    }
    else if(s.compare("path") == 0){
        m_tag = UploadSessionFinishError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("too_many_shared_folder_targets") == 0){
        m_tag = UploadSessionFinishError_TOO_MANY_SHARED_FOLDER_TARGETS;

    }
    else if(s.compare("other") == 0){
        m_tag = UploadSessionFinishError_OTHER;

    }
}

QString UploadSessionFinishError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadSessionFinishError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UploadSessionFinishError>  UploadSessionFinishError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UploadSessionFinishError> rv = std::unique_ptr<UploadSessionFinishError>(new UploadSessionFinishError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
