/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesListFolderContinueError.h"

namespace dropboxQt{

namespace files{
///ListFolderContinueError

ListFolderContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListFolderContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListFolderContinueError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case ListFolderContinueError_RESET:{
            if(!name.isEmpty())
                js[name] = QString("reset");
        }break;
        case ListFolderContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListFolderContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = ListFolderContinueError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("reset") == 0){
        m_tag = ListFolderContinueError_RESET;

    }
    else if(s.compare("other") == 0){
        m_tag = ListFolderContinueError_OTHER;

    }
}

QString ListFolderContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListFolderContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListFolderContinueError>  ListFolderContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListFolderContinueError> rv = std::unique_ptr<ListFolderContinueError>(new ListFolderContinueError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
