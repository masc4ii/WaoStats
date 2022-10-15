/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesCreateFolderError.h"

namespace dropboxQt{

namespace files{
///CreateFolderError

CreateFolderError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void CreateFolderError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case CreateFolderError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
    }//switch
}

void CreateFolderError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = CreateFolderError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
}

QString CreateFolderError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "CreateFolderError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<CreateFolderError>  CreateFolderError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<CreateFolderError> rv = std::unique_ptr<CreateFolderError>(new CreateFolderError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
