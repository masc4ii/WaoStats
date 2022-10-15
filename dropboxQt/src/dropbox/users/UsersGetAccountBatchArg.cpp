/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersGetAccountBatchArg.h"
using namespace dropboxQt;

namespace dropboxQt{

namespace users{
///GetAccountBatchArg

GetAccountBatchArg::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void GetAccountBatchArg::toJson(QJsonObject& js)const{

    js["account_ids"] = ingrl_list2jsonarray(m_account_ids);
}

void GetAccountBatchArg::fromJson(const QJsonObject& js){

    jsonarray2ingrl_list(js["account_ids"].toArray(), m_account_ids);
}

QString GetAccountBatchArg::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<GetAccountBatchArg>  GetAccountBatchArg::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<GetAccountBatchArg>  GetAccountBatchArg::factory::create(const QJsonObject& js)
{
    std::unique_ptr<GetAccountBatchArg> rv;
    rv = std::unique_ptr<GetAccountBatchArg>(new GetAccountBatchArg);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
