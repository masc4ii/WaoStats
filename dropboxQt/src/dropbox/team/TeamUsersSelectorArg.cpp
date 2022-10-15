/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamUsersSelectorArg.h"

namespace dropboxQt{

namespace team{
///UsersSelectorArg

UsersSelectorArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UsersSelectorArg::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UsersSelectorArg_TEAM_MEMBER_IDS:{
            if(!name.isEmpty())
                js[name] = QString("team_member_ids");
            js["team_member_ids"] = ingrl_list2jsonarray(m_team_member_ids);
        }break;
        case UsersSelectorArg_EXTERNAL_IDS:{
            if(!name.isEmpty())
                js[name] = QString("external_ids");
            js["external_ids"] = ingrl_list2jsonarray(m_external_ids);
        }break;
        case UsersSelectorArg_EMAILS:{
            if(!name.isEmpty())
                js[name] = QString("emails");
            js["emails"] = ingrl_list2jsonarray(m_emails);
        }break;
    }//switch
}

void UsersSelectorArg::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("team_member_ids") == 0){
        m_tag = UsersSelectorArg_TEAM_MEMBER_IDS;
        jsonarray2ingrl_list(js["team_member_ids"].toArray(), m_team_member_ids);
    }
    else if(s.compare("external_ids") == 0){
        m_tag = UsersSelectorArg_EXTERNAL_IDS;
        jsonarray2ingrl_list(js["external_ids"].toArray(), m_external_ids);
    }
    else if(s.compare("emails") == 0){
        m_tag = UsersSelectorArg_EMAILS;
        jsonarray2ingrl_list(js["emails"].toArray(), m_emails);
    }
}

QString UsersSelectorArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UsersSelectorArg");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UsersSelectorArg>  UsersSelectorArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UsersSelectorArg> rv = std::unique_ptr<UsersSelectorArg>(new UsersSelectorArg);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
