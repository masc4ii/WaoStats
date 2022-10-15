/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersRecoverError.h"

namespace dropboxQt{

namespace team{
///MembersRecoverError

MembersRecoverError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersRecoverError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UserSelectorError_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("user_not_found");
        }break;
        case MembersRecoverError_USER_UNRECOVERABLE:{
            if(!name.isEmpty())
                js[name] = QString("user_unrecoverable");
        }break;
        case MembersRecoverError_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_not_in_team");
        }break;
        case MembersRecoverError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MembersRecoverError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_not_found") == 0){
        m_tag = UserSelectorError_USER_NOT_FOUND;

    }
    if(s.compare("user_unrecoverable") == 0){
        m_tag = MembersRecoverError_USER_UNRECOVERABLE;

    }
    else if(s.compare("user_not_in_team") == 0){
        m_tag = MembersRecoverError_USER_NOT_IN_TEAM;

    }
    else if(s.compare("other") == 0){
        m_tag = MembersRecoverError_OTHER;

    }
}

QString MembersRecoverError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersRecoverError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersRecoverError>  MembersRecoverError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersRecoverError> rv = std::unique_ptr<MembersRecoverError>(new MembersRecoverError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
