/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersSuspendError.h"

namespace dropboxQt{

namespace team{
///MembersSuspendError

MembersSuspendError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersSuspendError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UserSelectorError_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("user_not_found");
        }break;
        case MembersDeactivateError_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_not_in_team");
        }break;
        case MembersDeactivateError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
        case MembersSuspendError_SUSPEND_INACTIVE_USER:{
            if(!name.isEmpty())
                js[name] = QString("suspend_inactive_user");
        }break;
        case MembersSuspendError_SUSPEND_LAST_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("suspend_last_admin");
        }break;
        case MembersSuspendError_TEAM_LICENSE_LIMIT:{
            if(!name.isEmpty())
                js[name] = QString("team_license_limit");
        }break;
    }//switch
}

void MembersSuspendError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_not_found") == 0){
        m_tag = UserSelectorError_USER_NOT_FOUND;

    }
    if(s.compare("user_not_in_team") == 0){
        m_tag = MembersDeactivateError_USER_NOT_IN_TEAM;

    }
    else if(s.compare("other") == 0){
        m_tag = MembersDeactivateError_OTHER;

    }
    if(s.compare("suspend_inactive_user") == 0){
        m_tag = MembersSuspendError_SUSPEND_INACTIVE_USER;

    }
    else if(s.compare("suspend_last_admin") == 0){
        m_tag = MembersSuspendError_SUSPEND_LAST_ADMIN;

    }
    else if(s.compare("team_license_limit") == 0){
        m_tag = MembersSuspendError_TEAM_LICENSE_LIMIT;

    }
}

QString MembersSuspendError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersSuspendError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersSuspendError>  MembersSuspendError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersSuspendError> rv = std::unique_ptr<MembersSuspendError>(new MembersSuspendError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
