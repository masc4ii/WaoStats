/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesWriteError.h"

namespace dropboxQt{

namespace files{
///WriteError

WriteError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void WriteError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case WriteError_MALFORMED_PATH:{
            if(!name.isEmpty())
                js[name] = QString("malformed_path");
            if(!m_malformed_path.isEmpty())
                js["malformed_path"] = QString(m_malformed_path);
        }break;
        case WriteError_CONFLICT:{
            if(!name.isEmpty())
                js[name] = QString("conflict");
            m_conflict.toJson(js, "conflict");
        }break;
        case WriteError_NO_WRITE_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_write_permission");
        }break;
        case WriteError_INSUFFICIENT_SPACE:{
            if(!name.isEmpty())
                js[name] = QString("insufficient_space");
        }break;
        case WriteError_DISALLOWED_NAME:{
            if(!name.isEmpty())
                js[name] = QString("disallowed_name");
        }break;
        case WriteError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void WriteError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("malformed_path") == 0){
        m_tag = WriteError_MALFORMED_PATH;
        m_malformed_path = js["malformed_path"].toString();
    }
    else if(s.compare("conflict") == 0){
        m_tag = WriteError_CONFLICT;
        m_conflict.fromJson(js["conflict"].toObject());
    }
    else if(s.compare("no_write_permission") == 0){
        m_tag = WriteError_NO_WRITE_PERMISSION;

    }
    else if(s.compare("insufficient_space") == 0){
        m_tag = WriteError_INSUFFICIENT_SPACE;

    }
    else if(s.compare("disallowed_name") == 0){
        m_tag = WriteError_DISALLOWED_NAME;

    }
    else if(s.compare("other") == 0){
        m_tag = WriteError_OTHER;

    }
}

QString WriteError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "WriteError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<WriteError>  WriteError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<WriteError> rv = std::unique_ptr<WriteError>(new WriteError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
