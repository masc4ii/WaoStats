/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersGetAccountError.h"

namespace dropboxQt{

namespace users{
///GetAccountError

GetAccountError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetAccountError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetAccountError_NO_ACCOUNT:{
            if(!name.isEmpty())
                js[name] = QString("no_account");
        }break;
        case GetAccountError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetAccountError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("no_account") == 0){
        m_tag = GetAccountError_NO_ACCOUNT;

    }
    else if(s.compare("other") == 0){
        m_tag = GetAccountError_OTHER;

    }
}

QString GetAccountError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetAccountError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetAccountError>  GetAccountError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetAccountError> rv = std::unique_ptr<GetAccountError>(new GetAccountError);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
