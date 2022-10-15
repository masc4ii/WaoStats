/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesListFolderLongpollError.h"

namespace dropboxQt{

namespace files{
///ListFolderLongpollError

ListFolderLongpollError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListFolderLongpollError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListFolderLongpollError_RESET:{
            if(!name.isEmpty())
                js[name] = QString("reset");
        }break;
        case ListFolderLongpollError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListFolderLongpollError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("reset") == 0){
        m_tag = ListFolderLongpollError_RESET;

    }
    else if(s.compare("other") == 0){
        m_tag = ListFolderLongpollError_OTHER;

    }
}

QString ListFolderLongpollError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListFolderLongpollError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListFolderLongpollError>  ListFolderLongpollError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListFolderLongpollError> rv = std::unique_ptr<ListFolderLongpollError>(new ListFolderLongpollError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
