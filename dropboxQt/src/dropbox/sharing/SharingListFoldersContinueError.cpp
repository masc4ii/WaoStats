/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFoldersContinueError.h"

namespace dropboxQt{

namespace sharing{
///ListFoldersContinueError

ListFoldersContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListFoldersContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListFoldersContinueError_INVALID_CURSOR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_cursor");
        }break;
        case ListFoldersContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListFoldersContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_cursor") == 0){
        m_tag = ListFoldersContinueError_INVALID_CURSOR;

    }
    else if(s.compare("other") == 0){
        m_tag = ListFoldersContinueError_OTHER;

    }
}

QString ListFoldersContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListFoldersContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListFoldersContinueError>  ListFoldersContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListFoldersContinueError> rv = std::unique_ptr<ListFoldersContinueError>(new ListFoldersContinueError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
