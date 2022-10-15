/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUpdateFolderMemberError.h"

namespace dropboxQt{

namespace sharing{
///UpdateFolderMemberError

UpdateFolderMemberError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UpdateFolderMemberError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UpdateFolderMemberError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case UpdateFolderMemberError_MEMBER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("member_error");
            m_member_error.toJson(js, "member_error");
        }break;
        case UpdateFolderMemberError_NO_EXPLICIT_ACCESS:{
            if(!name.isEmpty())
                js[name] = QString("no_explicit_access");
            m_no_explicit_access.toJson(js, "no_explicit_access");
        }break;
        case UpdateFolderMemberError_INSUFFICIENT_PLAN:{
            if(!name.isEmpty())
                js[name] = QString("insufficient_plan");
        }break;
        case UpdateFolderMemberError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case UpdateFolderMemberError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void UpdateFolderMemberError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = UpdateFolderMemberError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("member_error") == 0){
        m_tag = UpdateFolderMemberError_MEMBER_ERROR;
        m_member_error.fromJson(js["member_error"].toObject());
    }
    else if(s.compare("no_explicit_access") == 0){
        m_tag = UpdateFolderMemberError_NO_EXPLICIT_ACCESS;
        m_no_explicit_access.fromJson(js["no_explicit_access"].toObject());
    }
    else if(s.compare("insufficient_plan") == 0){
        m_tag = UpdateFolderMemberError_INSUFFICIENT_PLAN;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = UpdateFolderMemberError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = UpdateFolderMemberError_OTHER;

    }
}

QString UpdateFolderMemberError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UpdateFolderMemberError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UpdateFolderMemberError>  UpdateFolderMemberError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UpdateFolderMemberError> rv = std::unique_ptr<UpdateFolderMemberError>(new UpdateFolderMemberError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
