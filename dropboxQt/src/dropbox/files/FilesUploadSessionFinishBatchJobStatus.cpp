/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionFinishBatchJobStatus.h"

namespace dropboxQt{

namespace files{
///UploadSessionFinishBatchJobStatus

UploadSessionFinishBatchJobStatus::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadSessionFinishBatchJobStatus::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PollResultBase_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case UploadSessionFinishBatchJobStatus_COMPLETE:{
            if(!name.isEmpty())
                js[name] = QString("complete");
            js["complete"] = (QJsonObject)m_complete;
        }break;
    }//switch
}

void UploadSessionFinishBatchJobStatus::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("in_progress") == 0){
        m_tag = PollResultBase_IN_PROGRESS;

    }
    if(s.compare("complete") == 0){
        m_tag = UploadSessionFinishBatchJobStatus_COMPLETE;
        m_complete.fromJson(js["complete"].toObject());
    }
}

QString UploadSessionFinishBatchJobStatus::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadSessionFinishBatchJobStatus");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UploadSessionFinishBatchJobStatus>  UploadSessionFinishBatchJobStatus::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UploadSessionFinishBatchJobStatus> rv = std::unique_ptr<UploadSessionFinishBatchJobStatus>(new UploadSessionFinishBatchJobStatus);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
