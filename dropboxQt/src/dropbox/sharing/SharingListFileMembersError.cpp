/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListFileMembersError.h"

namespace dropboxQt{

namespace sharing{
///ListFileMembersError

ListFileMembersError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListFileMembersError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListFileMembersError_USER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("user_error");
            m_user_error.toJson(js, "user_error");
        }break;
        case ListFileMembersError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case ListFileMembersError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListFileMembersError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_error") == 0){
        m_tag = ListFileMembersError_USER_ERROR;
        m_user_error.fromJson(js["user_error"].toObject());
    }
    else if(s.compare("access_error") == 0){
        m_tag = ListFileMembersError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = ListFileMembersError_OTHER;

    }
}

QString ListFileMembersError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListFileMembersError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListFileMembersError>  ListFileMembersError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListFileMembersError> rv = std::unique_ptr<ListFileMembersError>(new ListFileMembersError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
