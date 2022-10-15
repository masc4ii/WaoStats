/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetFileMetadataError.h"

namespace dropboxQt{

namespace sharing{
///GetFileMetadataError

GetFileMetadataError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetFileMetadataError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetFileMetadataError_USER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("user_error");
            m_user_error.toJson(js, "user_error");
        }break;
        case GetFileMetadataError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case GetFileMetadataError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetFileMetadataError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("user_error") == 0){
        m_tag = GetFileMetadataError_USER_ERROR;
        m_user_error.fromJson(js["user_error"].toObject());
    }
    else if(s.compare("access_error") == 0){
        m_tag = GetFileMetadataError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = GetFileMetadataError_OTHER;

    }
}

QString GetFileMetadataError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetFileMetadataError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetFileMetadataError>  GetFileMetadataError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetFileMetadataError> rv = std::unique_ptr<GetFileMetadataError>(new GetFileMetadataError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
