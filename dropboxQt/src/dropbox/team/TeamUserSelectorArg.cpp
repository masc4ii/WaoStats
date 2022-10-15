/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamUserSelectorArg.h"

namespace dropboxQt{

namespace team{
///UserSelectorArg

UserSelectorArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UserSelectorArg::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UserSelectorArg_TEAM_MEMBER_ID:{
            if(!name.isEmpty())
                js[name] = QString("team_member_id");
            if(!m_team_member_id.isEmpty())
                js["team_member_id"] = QString(m_team_member_id);
        }break;
        case UserSelectorArg_EXTERNAL_ID:{
            if(!name.isEmpty())
                js[name] = QString("external_id");
            if(!m_external_id.isEmpty())
                js["external_id"] = QString(m_external_id);
        }break;
        case UserSelectorArg_EMAIL:{
            if(!name.isEmpty())
                js[name] = QString("email");
            if(!m_email.isEmpty())
                js["email"] = QString(m_email);
        }break;
    }//switch
}

void UserSelectorArg::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("team_member_id") == 0){
        m_tag = UserSelectorArg_TEAM_MEMBER_ID;
        m_team_member_id = js["team_member_id"].toString();
    }
    else if(s.compare("external_id") == 0){
        m_tag = UserSelectorArg_EXTERNAL_ID;
        m_external_id = js["external_id"].toString();
    }
    else if(s.compare("email") == 0){
        m_tag = UserSelectorArg_EMAIL;
        m_email = js["email"].toString();
    }
}

QString UserSelectorArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UserSelectorArg");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UserSelectorArg>  UserSelectorArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UserSelectorArg> rv = std::unique_ptr<UserSelectorArg>(new UserSelectorArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
