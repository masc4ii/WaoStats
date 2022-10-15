/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharingUserError.h"

namespace dropboxQt{

namespace sharing{
///SharingUserError

SharingUserError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharingUserError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharingUserError_EMAIL_UNVERIFIED:{
            if(!name.isEmpty())
                js[name] = QString("email_unverified");
        }break;
        case SharingUserError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharingUserError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("email_unverified") == 0){
        m_tag = SharingUserError_EMAIL_UNVERIFIED;

    }
    else if(s.compare("other") == 0){
        m_tag = SharingUserError_OTHER;

    }
}

QString SharingUserError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharingUserError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharingUserError>  SharingUserError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharingUserError> rv = std::unique_ptr<SharingUserError>(new SharingUserError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
