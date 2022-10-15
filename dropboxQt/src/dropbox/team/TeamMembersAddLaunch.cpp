/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersAddLaunch.h"

namespace dropboxQt{

namespace team{
///MembersAddLaunch

MembersAddLaunch::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersAddLaunch::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case LaunchResultBase_ASYNC_JOB_ID:{
            if(!name.isEmpty())
                js[name] = QString("async_job_id");
            if(!m_async_job_id.isEmpty())
                js["async_job_id"] = QString(m_async_job_id);
        }break;
        case MembersAddLaunch_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = struct_list2jsonarray(m_complete);
        }break;
    }//switch
}

void MembersAddLaunch::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("async_job_id") == 0){
        m_tag = LaunchResultBase_ASYNC_JOB_ID;
        m_async_job_id = js["async_job_id"].toString();
    }
    if(s.compare("complete") == 0){
        m_tag = MembersAddLaunch_COMPLETE;
        jsonarray2struct_list(js["complete"].toArray(), m_complete);
    }
}

QString MembersAddLaunch::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersAddLaunch");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersAddLaunch>  MembersAddLaunch::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersAddLaunch> rv = std::unique_ptr<MembersAddLaunch>(new MembersAddLaunch);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
