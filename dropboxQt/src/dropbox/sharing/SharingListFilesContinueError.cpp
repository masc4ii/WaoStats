/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFilesContinueError.h"

namespace dropboxQt{

namespace sharing{
///ListFilesContinueError

ListFilesContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListFilesContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListFilesContinueError_USER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("user_error");
            m_user_error.toJson(js, "user_error");
        }break;
        case ListFilesContinueError_INVALID_CURSOR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_cursor");
        }break;
        case ListFilesContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListFilesContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_error") == 0){
        m_tag = ListFilesContinueError_USER_ERROR;
        m_user_error.fromJson(js["user_error"].toObject());
    }
    else if(s.compare("invalid_cursor") == 0){
        m_tag = ListFilesContinueError_INVALID_CURSOR;

    }
    else if(s.compare("other") == 0){
        m_tag = ListFilesContinueError_OTHER;

    }
}

QString ListFilesContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListFilesContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListFilesContinueError>  ListFilesContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListFilesContinueError> rv = std::unique_ptr<ListFilesContinueError>(new ListFilesContinueError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
