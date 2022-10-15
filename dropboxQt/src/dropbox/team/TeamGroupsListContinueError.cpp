/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsListContinueError.h"

namespace dropboxQt{

namespace team{
///GroupsListContinueError

GroupsListContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupsListContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupsListContinueError_INVALID_CURSOR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_cursor");
        }break;
        case GroupsListContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GroupsListContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_cursor") == 0){
        m_tag = GroupsListContinueError_INVALID_CURSOR;

    }
    else if(s.compare("other") == 0){
        m_tag = GroupsListContinueError_OTHER;

    }
}

QString GroupsListContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupsListContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupsListContinueError>  GroupsListContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupsListContinueError> rv = std::unique_ptr<GroupsListContinueError>(new GroupsListContinueError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
