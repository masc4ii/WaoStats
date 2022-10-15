/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingShareFolderErrorBase.h"

namespace dropboxQt{

namespace sharing{
///ShareFolderErrorBase

ShareFolderErrorBase::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ShareFolderErrorBase::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ShareFolderErrorBase_EMAIL_UNVERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("email_unverified");
        }break;
        case ShareFolderErrorBase_BAD_PATH:{
            if(!name.isEmpty())
                js[name] = QString("bad_path");
            m_bad_path.toJson(js, "bad_path");
        }break;
        case ShareFolderErrorBase_TEAM_POLICY_DISALLOWS_MEMBER_POLICY:{
            if(!name.isEmpty())
                js[name] = QString("team_policy_disallows_member_policy");
        }break;
        case ShareFolderErrorBase_DISALLOWED_SHARED_LINK_POLICY:{
            if(!name.isEmpty())
                js[name] = QString("disallowed_shared_link_policy");
        }break;
        case ShareFolderErrorBase_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ShareFolderErrorBase::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("email_unverified") == 0){
        m_tag = ShareFolderErrorBase_EMAIL_UNVERIFIED;

    }
    else if(s.compare("bad_path") == 0){
        m_tag = ShareFolderErrorBase_BAD_PATH;
        m_bad_path.fromJson(js["bad_path"].toObject());
    }
    else if(s.compare("team_policy_disallows_member_policy") == 0){
        m_tag = ShareFolderErrorBase_TEAM_POLICY_DISALLOWS_MEMBER_POLICY;

    }
    else if(s.compare("disallowed_shared_link_policy") == 0){
        m_tag = ShareFolderErrorBase_DISALLOWED_SHARED_LINK_POLICY;

    }
    else if(s.compare("other") == 0){
        m_tag = ShareFolderErrorBase_OTHER;

    }
}

QString ShareFolderErrorBase::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ShareFolderErrorBase");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ShareFolderErrorBase>  ShareFolderErrorBase::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ShareFolderErrorBase> rv = std::unique_ptr<ShareFolderErrorBase>(new ShareFolderErrorBase);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
