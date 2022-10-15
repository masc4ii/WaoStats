/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFileErrorResult.h"

namespace dropboxQt{

namespace sharing{
///FileErrorResult

FileErrorResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void FileErrorResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case FileErrorResult_FILE_NOT_FOUND_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("file_not_found_error");
            if(!m_file_not_found_error.isEmpty())
                js["file_not_found_error"] = QString(m_file_not_found_error);
        }break;
        case FileErrorResult_INVALID_FILE_ACTION_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_file_action_error");
            if(!m_invalid_file_action_error.isEmpty())
                js["invalid_file_action_error"] = QString(m_invalid_file_action_error);
        }break;
        case FileErrorResult_PERMISSION_DENIED_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("permission_denied_error");
            if(!m_permission_denied_error.isEmpty())
                js["permission_denied_error"] = QString(m_permission_denied_error);
        }break;
        case FileErrorResult_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void FileErrorResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("file_not_found_error") == 0){
        m_tag = FileErrorResult_FILE_NOT_FOUND_ERROR;
        m_file_not_found_error = js["file_not_found_error"].toString();
    }
    else if(s.compare("invalid_file_action_error") == 0){
        m_tag = FileErrorResult_INVALID_FILE_ACTION_ERROR;
        m_invalid_file_action_error = js["invalid_file_action_error"].toString();
    }
    else if(s.compare("permission_denied_error") == 0){
        m_tag = FileErrorResult_PERMISSION_DENIED_ERROR;
        m_permission_denied_error = js["permission_denied_error"].toString();
    }
    else if(s.compare("other") == 0){
        m_tag = FileErrorResult_OTHER;

    }
}

QString FileErrorResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "FileErrorResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<FileErrorResult>  FileErrorResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<FileErrorResult> rv = std::unique_ptr<FileErrorResult>(new FileErrorResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
