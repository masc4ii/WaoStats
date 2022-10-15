/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingRemoveFileMemberError.h"

namespace dropboxQt{

namespace sharing{
///RemoveFileMemberError

RemoveFileMemberError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RemoveFileMemberError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RemoveFileMemberError_USER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("user_error");
            m_user_error.toJson(js, "user_error");
        }break;
        case RemoveFileMemberError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case RemoveFileMemberError_NO_EXPLICIT_ACCESS:{
            if(!name.isEmpty())
                js[name] = QString("no_explicit_access");
            js["no_explicit_access"] = (QJsonObject)m_no_explicit_access;
        }break;
        case RemoveFileMemberError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RemoveFileMemberError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_error") == 0){
        m_tag = RemoveFileMemberError_USER_ERROR;
        m_user_error.fromJson(js["user_error"].toObject());
    }
    else if(s.compare("access_error") == 0){
        m_tag = RemoveFileMemberError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("no_explicit_access") == 0){
        m_tag = RemoveFileMemberError_NO_EXPLICIT_ACCESS;
        m_no_explicit_access.fromJson(js["no_explicit_access"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = RemoveFileMemberError_OTHER;

    }
}

QString RemoveFileMemberError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RemoveFileMemberError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RemoveFileMemberError>  RemoveFileMemberError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RemoveFileMemberError> rv = std::unique_ptr<RemoveFileMemberError>(new RemoveFileMemberError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
