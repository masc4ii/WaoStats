/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersGetAccountBatchError.h"

namespace dropboxQt{

namespace users{
///GetAccountBatchError

GetAccountBatchError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetAccountBatchError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetAccountBatchError_NO_ACCOUNT:{
            if(!name.isEmpty())
                js[name] = QString("no_account");
            if(!m_no_account.isEmpty())
                js["no_account"] = QString(m_no_account);
        }break;
        case GetAccountBatchError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetAccountBatchError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("no_account") == 0){
        m_tag = GetAccountBatchError_NO_ACCOUNT;
        m_no_account = js["no_account"].toString();
    }
    else if(s.compare("other") == 0){
        m_tag = GetAccountBatchError_OTHER;

    }
}

QString GetAccountBatchError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetAccountBatchError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetAccountBatchError>  GetAccountBatchError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetAccountBatchError> rv = std::unique_ptr<GetAccountBatchError>(new GetAccountBatchError);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
