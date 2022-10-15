/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/async/AsyncPollError.h"

namespace dropboxQt{

namespace async{
///PollError

PollError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void PollError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollError_INVALID_ASYNC_JOB_ID:{
            if(!name.isEmpty())
                js[name] = QString("invalid_async_job_id");
        }break;
        case PollError_INTERNAL_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("internal_error");
        }break;
        case PollError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void PollError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("invalid_async_job_id") == 0){
        m_tag = PollError_INVALID_ASYNC_JOB_ID;

    }
    else if(s.compare("internal_error") == 0){
        m_tag = PollError_INTERNAL_ERROR;

    }
    else if(s.compare("other") == 0){
        m_tag = PollError_OTHER;

    }
}

QString PollError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "PollError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<PollError>  PollError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<PollError> rv = std::unique_ptr<PollError>(new PollError);
    rv->fromJson(js);
    return rv;
}

}//async
}//dropboxQt
