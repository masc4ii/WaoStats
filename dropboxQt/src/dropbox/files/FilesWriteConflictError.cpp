/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesWriteConflictError.h"

namespace dropboxQt{

namespace files{
///WriteConflictError

WriteConflictError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void WriteConflictError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case WriteConflictError_FILE:{
            if(!name.isEmpty())
                js[name] = QString("file");
        }break;
        case WriteConflictError_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("folder");
        }break;
        case WriteConflictError_FILE_ANCESTOR:{
            if(!name.isEmpty())
                js[name] = QString("file_ancestor");
        }break;
        case WriteConflictError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void WriteConflictError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("file") == 0){
        m_tag = WriteConflictError_FILE;

    }
    else if(s.compare("folder") == 0){
        m_tag = WriteConflictError_FOLDER;

    }
    else if(s.compare("file_ancestor") == 0){
        m_tag = WriteConflictError_FILE_ANCESTOR;

    }
    else if(s.compare("other") == 0){
        m_tag = WriteConflictError_OTHER;

    }
}

QString WriteConflictError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "WriteConflictError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<WriteConflictError>  WriteConflictError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<WriteConflictError> rv = std::unique_ptr<WriteConflictError>(new WriteConflictError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
