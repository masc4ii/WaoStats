/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMemberAddResult.h"

namespace dropboxQt{

namespace team{
///MemberAddResult

MemberAddResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MemberAddResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MemberAddResult_SUCCESS:{
            if(!name.isEmpty())
                js[name] = QString("success");
            js["success"] = (QJsonObject)m_success;
        }break;
        case MemberAddResult_TEAM_LICENSE_LIMIT:{
            if(!name.isEmpty())
                js[name] = QString("team_license_limit");
            if(!m_team_license_limit.isEmpty())
                js["team_license_limit"] = QString(m_team_license_limit);
        }break;
        case MemberAddResult_FREE_TEAM_MEMBER_LIMIT_REACHED:{
            if(!name.isEmpty())
                js[name] = QString("free_team_member_limit_reached");
            if(!m_free_team_member_limit_reached.isEmpty())
                js["free_team_member_limit_reached"] = QString(m_free_team_member_limit_reached);
        }break;
        case MemberAddResult_USER_ALREADY_ON_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_already_on_team");
            if(!m_user_already_on_team.isEmpty())
                js["user_already_on_team"] = QString(m_user_already_on_team);
        }break;
        case MemberAddResult_USER_ON_ANOTHER_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_on_another_team");
            if(!m_user_on_another_team.isEmpty())
                js["user_on_another_team"] = QString(m_user_on_another_team);
        }break;
        case MemberAddResult_USER_ALREADY_PAIRED:{
            if(!name.isEmpty())
                js[name] = QString("user_already_paired");
            if(!m_user_already_paired.isEmpty())
                js["user_already_paired"] = QString(m_user_already_paired);
        }break;
        case MemberAddResult_USER_MIGRATION_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("user_migration_failed");
            if(!m_user_migration_failed.isEmpty())
                js["user_migration_failed"] = QString(m_user_migration_failed);
        }break;
        case MemberAddResult_DUPLICATE_EXTERNAL_MEMBER_ID:{
            if(!name.isEmpty())
                js[name] = QString("duplicate_external_member_id");
            if(!m_duplicate_external_member_id.isEmpty())
                js["duplicate_external_member_id"] = QString(m_duplicate_external_member_id);
        }break;
        case MemberAddResult_USER_CREATION_FAILED:{
            if(!name.isEmpty())
                js[name] = QString("user_creation_failed");
            if(!m_user_creation_failed.isEmpty())
                js["user_creation_failed"] = QString(m_user_creation_failed);
        }break;
    }//switch
}

void MemberAddResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("success") == 0){
        m_tag = MemberAddResult_SUCCESS;
        m_success.fromJson(js["success"].toObject());
    }
    else if(s.compare("team_license_limit") == 0){
        m_tag = MemberAddResult_TEAM_LICENSE_LIMIT;
        m_team_license_limit = js["team_license_limit"].toString();
    }
    else if(s.compare("free_team_member_limit_reached") == 0){
        m_tag = MemberAddResult_FREE_TEAM_MEMBER_LIMIT_REACHED;
        m_free_team_member_limit_reached = js["free_team_member_limit_reached"].toString();
    }
    else if(s.compare("user_already_on_team") == 0){
        m_tag = MemberAddResult_USER_ALREADY_ON_TEAM;
        m_user_already_on_team = js["user_already_on_team"].toString();
    }
    else if(s.compare("user_on_another_team") == 0){
        m_tag = MemberAddResult_USER_ON_ANOTHER_TEAM;
        m_user_on_another_team = js["user_on_another_team"].toString();
    }
    else if(s.compare("user_already_paired") == 0){
        m_tag = MemberAddResult_USER_ALREADY_PAIRED;
        m_user_already_paired = js["user_already_paired"].toString();
    }
    else if(s.compare("user_migration_failed") == 0){
        m_tag = MemberAddResult_USER_MIGRATION_FAILED;
        m_user_migration_failed = js["user_migration_failed"].toString();
    }
    else if(s.compare("duplicate_external_member_id") == 0){
        m_tag = MemberAddResult_DUPLICATE_EXTERNAL_MEMBER_ID;
        m_duplicate_external_member_id = js["duplicate_external_member_id"].toString();
    }
    else if(s.compare("user_creation_failed") == 0){
        m_tag = MemberAddResult_USER_CREATION_FAILED;
        m_user_creation_failed = js["user_creation_failed"].toString();
    }
}

QString MemberAddResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MemberAddResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MemberAddResult>  MemberAddResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MemberAddResult> rv = std::unique_ptr<MemberAddResult>(new MemberAddResult);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
