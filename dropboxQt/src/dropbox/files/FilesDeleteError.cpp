/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesDeleteError.h"

namespace dropboxQt{

namespace files{
///DeleteError

DeleteError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void DeleteError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case DeleteError_PATH_LOOKUP:{
            if(!name.isEmpty())
                js[name] = QString("path_lookup");
            m_path_lookup.toJson(js, "path_lookup");
        }break;
        case DeleteError_PATH_WRITE:{
            if(!name.isEmpty())
                js[name] = QString("path_write");
            m_path_write.toJson(js, "path_write");
        }break;
        case DeleteError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void DeleteError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path_lookup") == 0){
        m_tag = DeleteError_PATH_LOOKUP;
        m_path_lookup.fromJson(js["path_lookup"].toObject());
    }
    else if(s.compare("path_write") == 0){
        m_tag = DeleteError_PATH_WRITE;
        m_path_write.fromJson(js["path_write"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = DeleteError_OTHER;

    }
}

QString DeleteError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "DeleteError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<DeleteError>  DeleteError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<DeleteError> rv = std::unique_ptr<DeleteError>(new DeleteError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
