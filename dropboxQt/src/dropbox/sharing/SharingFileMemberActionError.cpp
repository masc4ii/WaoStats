/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFileMemberActionError.h"

namespace dropboxQt{

namespace sharing{
///FileMemberActionError

FileMemberActionError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void FileMemberActionError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case FileMemberActionError_INVALID_MEMBER:{
            if(!name.isEmpty())
                js[name] = QString("invalid_member");
        }break;
        case FileMemberActionError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case FileMemberActionError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case FileMemberActionError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void FileMemberActionError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_member") == 0){
        m_tag = FileMemberActionError_INVALID_MEMBER;

    }
    else if(s.compare("no_permission") == 0){
        m_tag = FileMemberActionError_NO_PERMISSION;

    }
    else if(s.compare("access_error") == 0){
        m_tag = FileMemberActionError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = FileMemberActionError_OTHER;

    }
}

QString FileMemberActionError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "FileMemberActionError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<FileMemberActionError>  FileMemberActionError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<FileMemberActionError> rv = std::unique_ptr<FileMemberActionError>(new FileMemberActionError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
