/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupMembersAddError.h"

namespace dropboxQt{

namespace team{
///GroupMembersAddError

GroupMembersAddError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupMembersAddError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupSelectorError_GROUP_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("group_not_found");
        }break;
        case GroupSelectorError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case GroupMembersAddError_DUPLICATE_USER:{
            if(!name.isEmpty())
                js[name] = QString("duplicate_user");
        }break;
        case GroupMembersAddError_GROUP_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("group_not_in_team");
        }break;
        case GroupMembersAddError_MEMBERS_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("members_not_in_team");
            js["members_not_in_team"] = ingrl_list2jsonarray(m_members_not_in_team);
        }break;
        case GroupMembersAddError_USERS_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("users_not_found");
            js["users_not_found"] = ingrl_list2jsonarray(m_users_not_found);
        }break;
        case GroupMembersAddError_USER_MUST_BE_ACTIVE_TO_BE_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("user_must_be_active_to_be_owner");
        }break;
        case GroupMembersAddError_USER_CANNOT_BE_MANAGER_OF_COMPANY_MANAGED_GROUP:{
            if(!name.isEmpty())
                js[name] = QString("user_cannot_be_manager_of_company_managed_group");
            js["user_cannot_be_manager_of_company_managed_group"] = ingrl_list2jsonarray(m_user_cannot_be_manager_of_company_managed_group);
        }break;
    }//switch
}

void GroupMembersAddError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("group_not_found") == 0){
        m_tag = GroupSelectorError_GROUP_NOT_FOUND;

    }
    else if(s.compare("other") == 0){
        m_tag = GroupSelectorError_OTHER;

    }
    if(s.compare("duplicate_user") == 0){
        m_tag = GroupMembersAddError_DUPLICATE_USER;

    }
    else if(s.compare("group_not_in_team") == 0){
        m_tag = GroupMembersAddError_GROUP_NOT_IN_TEAM;

    }
    else if(s.compare("members_not_in_team") == 0){
        m_tag = GroupMembersAddError_MEMBERS_NOT_IN_TEAM;
        jsonarray2ingrl_list(js["members_not_in_team"].toArray(), m_members_not_in_team);
    }
    else if(s.compare("users_not_found") == 0){
        m_tag = GroupMembersAddError_USERS_NOT_FOUND;
        jsonarray2ingrl_list(js["users_not_found"].toArray(), m_users_not_found);
    }
    else if(s.compare("user_must_be_active_to_be_owner") == 0){
        m_tag = GroupMembersAddError_USER_MUST_BE_ACTIVE_TO_BE_OWNER;

    }
    else if(s.compare("user_cannot_be_manager_of_company_managed_group") == 0){
        m_tag = GroupMembersAddError_USER_CANNOT_BE_MANAGER_OF_COMPANY_MANAGED_GROUP;
        jsonarray2ingrl_list(js["user_cannot_be_manager_of_company_managed_group"].toArray(), m_user_cannot_be_manager_of_company_managed_group);
    }
}

QString GroupMembersAddError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupMembersAddError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupMembersAddError>  GroupMembersAddError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupMembersAddError> rv = std::unique_ptr<GroupMembersAddError>(new GroupMembersAddError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
