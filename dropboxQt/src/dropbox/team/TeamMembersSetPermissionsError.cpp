/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersSetPermissionsError.h"

namespace dropboxQt{

namespace team{
///MembersSetPermissionsError

MembersSetPermissionsError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersSetPermissionsError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UserSelectorError_USER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("user_not_found");
        }break;
        case MembersSetPermissionsError_LAST_ADMIN:{
            if(!name.isEmpty())
                js[name] = QString("last_admin");
        }break;
        case MembersSetPermissionsError_USER_NOT_IN_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("user_not_in_team");
        }break;
        case MembersSetPermissionsError_CANNOT_SET_PERMISSIONS:{
            if(!name.isEmpty())
                js[name] = QString("cannot_set_permissions");
        }break;
        case MembersSetPermissionsError_TEAM_LICENSE_LIMIT:{
            if(!name.isEmpty())
                js[name] = QString("team_license_limit");
        }break;
        case MembersSetPermissionsError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MembersSetPermissionsError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_not_found") == 0){
        m_tag = UserSelectorError_USER_NOT_FOUND;

    }
    if(s.compare("last_admin") == 0){
        m_tag = MembersSetPermissionsError_LAST_ADMIN;

    }
    else if(s.compare("user_not_in_team") == 0){
        m_tag = MembersSetPermissionsError_USER_NOT_IN_TEAM;

    }
    else if(s.compare("cannot_set_permissions") == 0){
        m_tag = MembersSetPermissionsError_CANNOT_SET_PERMISSIONS;

    }
    else if(s.compare("team_license_limit") == 0){
        m_tag = MembersSetPermissionsError_TEAM_LICENSE_LIMIT;

    }
    else if(s.compare("other") == 0){
        m_tag = MembersSetPermissionsError_OTHER;

    }
}

QString MembersSetPermissionsError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersSetPermissionsError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersSetPermissionsError>  MembersSetPermissionsError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersSetPermissionsError> rv = std::unique_ptr<MembersSetPermissionsError>(new MembersSetPermissionsError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
