/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionFinishBatchResultEntry.h"

namespace dropboxQt{

namespace files{
///UploadSessionFinishBatchResultEntry

UploadSessionFinishBatchResultEntry::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadSessionFinishBatchResultEntry::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UploadSessionFinishBatchResultEntry_SUCCESS:{
            if(!name.isEmpty())
                js[name] = QString("success");
            js["success"] = (QJsonObject)m_success;
        }break;
        case UploadSessionFinishBatchResultEntry_FAILURE:{
            if(!name.isEmpty())
                js[name] = QString("failure");
            m_failure.toJson(js, "failure");
        }break;
    }//switch
}

void UploadSessionFinishBatchResultEntry::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("success") == 0){
        m_tag = UploadSessionFinishBatchResultEntry_SUCCESS;
        m_success.fromJson(js["success"].toObject());
    }
    else if(s.compare("failure") == 0){
        m_tag = UploadSessionFinishBatchResultEntry_FAILURE;
        m_failure.fromJson(js["failure"].toObject());
    }
}

QString UploadSessionFinishBatchResultEntry::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadSessionFinishBatchResultEntry");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UploadSessionFinishBatchResultEntry>  UploadSessionFinishBatchResultEntry::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UploadSessionFinishBatchResultEntry> rv = std::unique_ptr<UploadSessionFinishBatchResultEntry>(new UploadSessionFinishBatchResultEntry);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
