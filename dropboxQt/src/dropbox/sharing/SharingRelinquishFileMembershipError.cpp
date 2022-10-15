/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRelinquishFileMembershipError.h"

namespace dropboxQt{

namespace sharing{
///RelinquishFileMembershipError

RelinquishFileMembershipError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RelinquishFileMembershipError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RelinquishFileMembershipError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case RelinquishFileMembershipError_GROUP_ACCESS:{
            if(!name.isEmpty())
                js[name] = QString("group_access");
        }break;
        case RelinquishFileMembershipError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case RelinquishFileMembershipError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RelinquishFileMembershipError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = RelinquishFileMembershipError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("group_access") == 0){
        m_tag = RelinquishFileMembershipError_GROUP_ACCESS;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = RelinquishFileMembershipError_NO_PERMISSION;

    }
    else if(s.compare("other") == 0){
        m_tag = RelinquishFileMembershipError_OTHER;

    }
}

QString RelinquishFileMembershipError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RelinquishFileMembershipError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RelinquishFileMembershipError>  RelinquishFileMembershipError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RelinquishFileMembershipError> rv = std::unique_ptr<RelinquishFileMembershipError>(new RelinquishFileMembershipError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
