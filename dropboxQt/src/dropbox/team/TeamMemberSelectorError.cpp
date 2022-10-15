/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMemberSelectorError.h"

namespace dropboxQt{

namespace team{
///MemberSelectorError

MemberSelectorError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MemberSelectorError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UserSelectorError_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("user_not_found");
        }break;
        case MemberSelectorError_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_not_in_team");
        }break;
    }//switch
}

void MemberSelectorError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_not_found") == 0){
        m_tag = UserSelectorError_USER_NOT_FOUND;

    }
    if(s.compare("user_not_in_team") == 0){
        m_tag = MemberSelectorError_USER_NOT_IN_TEAM;

    }
}

QString MemberSelectorError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MemberSelectorError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MemberSelectorError>  MemberSelectorError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MemberSelectorError> rv = std::unique_ptr<MemberSelectorError>(new MemberSelectorError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
