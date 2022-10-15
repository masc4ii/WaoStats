/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedFolderMemberError.h"

namespace dropboxQt{

namespace sharing{
///SharedFolderMemberError

SharedFolderMemberError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedFolderMemberError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedFolderMemberError_INVALID_DROPBOX_ID:{
            if(!name.isEmpty())
                js[name] = QString("invalid_dropbox_id");
        }break;
        case SharedFolderMemberError_NOT_A_MEMBER:{
            if(!name.isEmpty())
                js[name] = QString("not_a_member");
        }break;
        case SharedFolderMemberError_NO_EXPLICIT_ACCESS:{
            if(!name.isEmpty())
                js[name] = QString("no_explicit_access");
            js["no_explicit_access"] = (QJsonObject)m_no_explicit_access;
        }break;
        case SharedFolderMemberError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedFolderMemberError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_dropbox_id") == 0){
        m_tag = SharedFolderMemberError_INVALID_DROPBOX_ID;

    }
    else if(s.compare("not_a_member") == 0){
        m_tag = SharedFolderMemberError_NOT_A_MEMBER;

    }
    else if(s.compare("no_explicit_access") == 0){
        m_tag = SharedFolderMemberError_NO_EXPLICIT_ACCESS;
        m_no_explicit_access.fromJson(js["no_explicit_access"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = SharedFolderMemberError_OTHER;

    }
}

QString SharedFolderMemberError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedFolderMemberError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedFolderMemberError>  SharedFolderMemberError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedFolderMemberError> rv = std::unique_ptr<SharedFolderMemberError>(new SharedFolderMemberError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
