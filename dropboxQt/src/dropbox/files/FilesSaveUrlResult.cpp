/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesSaveUrlResult.h"

namespace dropboxQt{

namespace files{
///SaveUrlResult

SaveUrlResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SaveUrlResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case LaunchResultBase_ASYNC_JOB_ID:{
            if(!name.isEmpty())
                js[name] = QString("async_job_id");
            if(!m_async_job_id.isEmpty())
                js["async_job_id"] = QString(m_async_job_id);
        }break;
        case SaveUrlResult_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = (QJsonObject)m_complete;
        }break;
    }//switch
}

void SaveUrlResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("async_job_id") == 0){
        m_tag = LaunchResultBase_ASYNC_JOB_ID;
        m_async_job_id = js["async_job_id"].toString();
    }
    if(s.compare("complete") == 0){
        m_tag = SaveUrlResult_COMPLETE;
        m_complete.fromJson(js["complete"].toObject());
    }
}

QString SaveUrlResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SaveUrlResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SaveUrlResult>  SaveUrlResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SaveUrlResult> rv = std::unique_ptr<SaveUrlResult>(new SaveUrlResult);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
