/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedLinkAccessFailureReason.h"

namespace dropboxQt{

namespace sharing{
///SharedLinkAccessFailureReason

SharedLinkAccessFailureReason::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedLinkAccessFailureReason::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedLinkAccessFailureReason_LOGIN_REQUIRED:{
            if(!name.isEmpty())
                js[name] = QString("login_required");
        }break;
        case SharedLinkAccessFailureReason_EMAIL_VERIFY_REQUIRED:{
            if(!name.isEmpty())
                js[name] = QString("email_verify_required");
        }break;
        case SharedLinkAccessFailureReason_PASSWORD_REQUIRED:{
            if(!name.isEmpty())
                js[name] = QString("password_required");
        }break;
        case SharedLinkAccessFailureReason_TEAM_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("team_only");
        }break;
        case SharedLinkAccessFailureReason_OWNER_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("owner_only");
        }break;
        case SharedLinkAccessFailureReason_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedLinkAccessFailureReason::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("login_required") == 0){
        m_tag = SharedLinkAccessFailureReason_LOGIN_REQUIRED;

    }
    else if(s.compare("email_verify_required") == 0){
        m_tag = SharedLinkAccessFailureReason_EMAIL_VERIFY_REQUIRED;

    }
    else if(s.compare("password_required") == 0){
        m_tag = SharedLinkAccessFailureReason_PASSWORD_REQUIRED;

    }
    else if(s.compare("team_only") == 0){
        m_tag = SharedLinkAccessFailureReason_TEAM_ONLY;

    }
    else if(s.compare("owner_only") == 0){
        m_tag = SharedLinkAccessFailureReason_OWNER_ONLY;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedLinkAccessFailureReason_OTHER;

    }
}

QString SharedLinkAccessFailureReason::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedLinkAccessFailureReason");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedLinkAccessFailureReason>  SharedLinkAccessFailureReason::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedLinkAccessFailureReason> rv = std::unique_ptr<SharedLinkAccessFailureReason>(new SharedLinkAccessFailureReason);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
