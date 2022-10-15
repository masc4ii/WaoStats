/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "auth"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/auth/AuthRateLimitReason.h"

namespace dropboxQt{

namespace auth{
///RateLimitReason

RateLimitReason::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RateLimitReason::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RateLimitReason_TOO_MANY_REQUESTS:{
            if(!name.isEmpty())
                js[name] = QString("too_many_requests");
        }break;
        case RateLimitReason_TOO_MANY_WRITE_OPERATIONS:{
            if(!name.isEmpty())
                js[name] = QString("too_many_write_operations");
        }break;
        case RateLimitReason_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RateLimitReason::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("too_many_requests") == 0){
        m_tag = RateLimitReason_TOO_MANY_REQUESTS;

    }
    else if(s.compare("too_many_write_operations") == 0){
        m_tag = RateLimitReason_TOO_MANY_WRITE_OPERATIONS;

    }
    else if(s.compare("other") == 0){
        m_tag = RateLimitReason_OTHER;

    }
}

QString RateLimitReason::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RateLimitReason");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RateLimitReason>  RateLimitReason::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RateLimitReason> rv = std::unique_ptr<RateLimitReason>(new RateLimitReason);
    rv->fromJson(js);
    return rv;
}

}//auth
}//dropboxQt
