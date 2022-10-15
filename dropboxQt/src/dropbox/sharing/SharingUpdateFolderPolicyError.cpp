/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUpdateFolderPolicyError.h"

namespace dropboxQt{

namespace sharing{
///UpdateFolderPolicyError

UpdateFolderPolicyError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UpdateFolderPolicyError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UpdateFolderPolicyError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case UpdateFolderPolicyError_NOT_ON_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("not_on_team");
        }break;
        case UpdateFolderPolicyError_TEAM_POLICY_DISALLOWS_MEMBER_POLICY:{
            if(!name.isEmpty())
                js[name] = QString("team_policy_disallows_member_policy");
        }break;
        case UpdateFolderPolicyError_DISALLOWED_SHARED_LINK_POLICY:{
            if(!name.isEmpty())
                js[name] = QString("disallowed_shared_link_policy");
        }break;
        case UpdateFolderPolicyError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case UpdateFolderPolicyError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void UpdateFolderPolicyError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = UpdateFolderPolicyError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("not_on_team") == 0){
        m_tag = UpdateFolderPolicyError_NOT_ON_TEAM;

    }
    else if(s.compare("team_policy_disallows_member_policy") == 0){
        m_tag = UpdateFolderPolicyError_TEAM_POLICY_DISALLOWS_MEMBER_POLICY;

    }
    else if(s.compare("disallowed_shared_link_policy") == 0){
        m_tag = UpdateFolderPolicyError_DISALLOWED_SHARED_LINK_POLICY;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = UpdateFolderPolicyError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = UpdateFolderPolicyError_OTHER;

    }
}

QString UpdateFolderPolicyError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UpdateFolderPolicyError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UpdateFolderPolicyError>  UpdateFolderPolicyError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UpdateFolderPolicyError> rv = std::unique_ptr<UpdateFolderPolicyError>(new UpdateFolderPolicyError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
