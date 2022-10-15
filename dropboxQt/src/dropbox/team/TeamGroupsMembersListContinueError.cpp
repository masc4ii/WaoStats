/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsMembersListContinueError.h"

namespace dropboxQt{

namespace team{
///GroupsMembersListContinueError

GroupsMembersListContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupsMembersListContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupsMembersListContinueError_INVALID_CURSOR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_cursor");
        }break;
        case GroupsMembersListContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GroupsMembersListContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_cursor") == 0){
        m_tag = GroupsMembersListContinueError_INVALID_CURSOR;

    }
    else if(s.compare("other") == 0){
        m_tag = GroupsMembersListContinueError_OTHER;

    }
}

QString GroupsMembersListContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupsMembersListContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupsMembersListContinueError>  GroupsMembersListContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupsMembersListContinueError> rv = std::unique_ptr<GroupsMembersListContinueError>(new GroupsMembersListContinueError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
