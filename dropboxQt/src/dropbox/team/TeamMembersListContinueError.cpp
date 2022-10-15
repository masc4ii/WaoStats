/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersListContinueError.h"

namespace dropboxQt{

namespace team{
///MembersListContinueError

MembersListContinueError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersListContinueError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MembersListContinueError_INVALID_CURSOR:{
            if(!name.isEmpty())
                js[name] = QString("invalid_cursor");
        }break;
        case MembersListContinueError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MembersListContinueError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_cursor") == 0){
        m_tag = MembersListContinueError_INVALID_CURSOR;

    }
    else if(s.compare("other") == 0){
        m_tag = MembersListContinueError_OTHER;

    }
}

QString MembersListContinueError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersListContinueError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersListContinueError>  MembersListContinueError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersListContinueError> rv = std::unique_ptr<MembersListContinueError>(new MembersListContinueError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
