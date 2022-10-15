/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersGetAccountArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///GetAccountArg

GetAccountArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetAccountArg::toJson(QJsonObject& js)const{

    if(!m_account_id.isEmpty())
        js["account_id"] = QString(m_account_id);
}

void GetAccountArg::fromJson(const QJsonObject& js){

    m_account_id = js["account_id"].toString();
}

QString GetAccountArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetAccountArg>  GetAccountArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetAccountArg>  GetAccountArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetAccountArg> rv;
    rv = std::unique_ptr<GetAccountArg>(new GetAccountArg);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
