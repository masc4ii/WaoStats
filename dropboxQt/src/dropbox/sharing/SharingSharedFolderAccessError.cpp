/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedFolderAccessError.h"

namespace dropboxQt{

namespace sharing{
///SharedFolderAccessError

SharedFolderAccessError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedFolderAccessError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedFolderAccessError_INVALID_ID:{
            if(!name.isEmpty())
                js[name] = QString("invalid_id");
        }break;
        case SharedFolderAccessError_NOT_A_MEMBER:{
            if(!name.isEmpty())
                js[name] = QString("not_a_member");
        }break;
        case SharedFolderAccessError_EMAIL_UNVERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("email_unverified");
        }break;
        case SharedFolderAccessError_UNMOUNTED:{
            if(!name.isEmpty())
                js[name] = QString("unmounted");
        }break;
        case SharedFolderAccessError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedFolderAccessError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_id") == 0){
        m_tag = SharedFolderAccessError_INVALID_ID;

    }
    else if(s.compare("not_a_member") == 0){
        m_tag = SharedFolderAccessError_NOT_A_MEMBER;

    }
    else if(s.compare("email_unverified") == 0){
        m_tag = SharedFolderAccessError_EMAIL_UNVERIFIED;

    }
    else if(s.compare("unmounted") == 0){
        m_tag = SharedFolderAccessError_UNMOUNTED;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedFolderAccessError_OTHER;

    }
}

QString SharedFolderAccessError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedFolderAccessError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedFolderAccessError>  SharedFolderAccessError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedFolderAccessError> rv = std::unique_ptr<SharedFolderAccessError>(new SharedFolderAccessError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
