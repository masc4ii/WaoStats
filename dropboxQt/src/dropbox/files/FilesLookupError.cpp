/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesLookupError.h"

namespace dropboxQt{

namespace files{
///LookupError

LookupError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void LookupError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case LookupError_MALFORMED_PATH:{
            if(!name.isEmpty())
                js[name] = QString("malformed_path");
            if(!m_malformed_path.isEmpty())
                js["malformed_path"] = QString(m_malformed_path);
        }break;
        case LookupError_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("not_found");
        }break;
        case LookupError_NOT_FILE:{
            if(!name.isEmpty())
                js[name] = QString("not_file");
        }break;
        case LookupError_NOT_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("not_folder");
        }break;
        case LookupError_RESTRICTED_CONTENT:{
            if(!name.isEmpty())
                js[name] = QString("restricted_content");
        }break;
        case LookupError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void LookupError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("malformed_path") == 0){
        m_tag = LookupError_MALFORMED_PATH;
        m_malformed_path = js["malformed_path"].toString();
    }
    else if(s.compare("not_found") == 0){
        m_tag = LookupError_NOT_FOUND;

    }
    else if(s.compare("not_file") == 0){
        m_tag = LookupError_NOT_FILE;

    }
    else if(s.compare("not_folder") == 0){
        m_tag = LookupError_NOT_FOLDER;

    }
    else if(s.compare("restricted_content") == 0){
        m_tag = LookupError_RESTRICTED_CONTENT;

    }
    else if(s.compare("other") == 0){
        m_tag = LookupError_OTHER;

    }
}

QString LookupError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "LookupError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<LookupError>  LookupError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<LookupError> rv = std::unique_ptr<LookupError>(new LookupError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
