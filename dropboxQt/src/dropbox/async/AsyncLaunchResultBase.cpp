/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "async"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/async/AsyncLaunchResultBase.h"

namespace dropboxQt{

namespace async{
///LaunchResultBase

LaunchResultBase::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void LaunchResultBase::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case LaunchResultBase_ASYNC_JOB_ID:{
            if(!name.isEmpty())
                js[name] = QString("async_job_id");
            if(!m_async_job_id.isEmpty())
                js["async_job_id"] = QString(m_async_job_id);
        }break;
    }//switch
}

void LaunchResultBase::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("async_job_id") == 0){
        m_tag = LaunchResultBase_ASYNC_JOB_ID;
        m_async_job_id = js["async_job_id"].toString();
    }
}

QString LaunchResultBase::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "LaunchResultBase");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<LaunchResultBase>  LaunchResultBase::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<LaunchResultBase> rv = std::unique_ptr<LaunchResultBase>(new LaunchResultBase);
    rv->fromJson(js);
    return rv;
}

}//async
}//dropboxQt
