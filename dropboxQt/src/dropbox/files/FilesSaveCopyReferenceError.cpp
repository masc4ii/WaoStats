/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSaveCopyReferenceError.h"

namespace dropboxQt{

namespace files{
///SaveCopyReferenceError

SaveCopyReferenceError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SaveCopyReferenceError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SaveCopyReferenceError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case SaveCopyReferenceError_INVALID_COPY_REFERENCE:{
            if(!name.isEmpty())
                js[name] = QString("invalid_copy_reference");
        }break;
        case SaveCopyReferenceError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case SaveCopyReferenceError_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("not_found");
        }break;
        case SaveCopyReferenceError_TOO_MANY_FILES:{
            if(!name.isEmpty())
                js[name] = QString("too_many_files");
        }break;
        case SaveCopyReferenceError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SaveCopyReferenceError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = SaveCopyReferenceError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("invalid_copy_reference") == 0){
        m_tag = SaveCopyReferenceError_INVALID_COPY_REFERENCE;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = SaveCopyReferenceError_NO_PERMISSION;

    }
    else if(s.compare("not_found") == 0){
        m_tag = SaveCopyReferenceError_NOT_FOUND;

    }
    else if(s.compare("too_many_files") == 0){
        m_tag = SaveCopyReferenceError_TOO_MANY_FILES;

    }
    else if(s.compare("other") == 0){
        m_tag = SaveCopyReferenceError_OTHER;

    }
}

QString SaveCopyReferenceError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SaveCopyReferenceError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SaveCopyReferenceError>  SaveCopyReferenceError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SaveCopyReferenceError> rv = std::unique_ptr<SaveCopyReferenceError>(new SaveCopyReferenceError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
