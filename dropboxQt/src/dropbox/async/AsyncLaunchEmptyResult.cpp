/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/async/AsyncLaunchEmptyResult.h"

namespace dropboxQt{

namespace async{
///LaunchEmptyResult

LaunchEmptyResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void LaunchEmptyResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case LaunchResultBase_ASYNC_JOB_ID:{
            if(!name.isEmpty())
                js[name] = QString("async_job_id");
            if(!m_async_job_id.isEmpty())
                js["async_job_id"] = QString(m_async_job_id);
        }break;
        case LaunchEmptyResult_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
        }break;
    }//switch
}

void LaunchEmptyResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("async_job_id") == 0){
        m_tag = LaunchResultBase_ASYNC_JOB_ID;
        m_async_job_id = js["async_job_id"].toString();
    }
    if(s.compare("complete") == 0){
        m_tag = LaunchEmptyResult_COMPLETE;

    }
}

QString LaunchEmptyResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "LaunchEmptyResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<LaunchEmptyResult>  LaunchEmptyResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<LaunchEmptyResult> rv = std::unique_ptr<LaunchEmptyResult>(new LaunchEmptyResult);
    rv->fromJson(js);
    return rv;
}

}//async
}//dropboxQt
