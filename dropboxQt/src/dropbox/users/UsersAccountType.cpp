/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersAccountType.h"

namespace dropboxQt{

namespace users{
///AccountType

AccountType::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AccountType::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AccountType_BASIC:{
            if(!name.isEmpty())
                js[name] = QString("basic");
        }break;
        case AccountType_PRO:{
            if(!name.isEmpty())
                js[name] = QString("pro");
        }break;
        case AccountType_BUSINESS:{
            if(!name.isEmpty())
                js[name] = QString("business");
        }break;
    }//switch
}

void AccountType::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("basic") == 0){
        m_tag = AccountType_BASIC;

    }
    else if(s.compare("pro") == 0){
        m_tag = AccountType_PRO;

    }
    else if(s.compare("business") == 0){
        m_tag = AccountType_BUSINESS;

    }
}

QString AccountType::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AccountType");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AccountType>  AccountType::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AccountType> rv = std::unique_ptr<AccountType>(new AccountType);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
