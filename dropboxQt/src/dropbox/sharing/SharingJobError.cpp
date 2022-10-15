/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingJobError.h"

namespace dropboxQt{

namespace sharing{
///JobError

JobError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void JobError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case JobError_UNSHARE_FOLDER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("unshare_folder_error");
            m_unshare_folder_error.toJson(js, "unshare_folder_error");
        }break;
        case JobError_REMOVE_FOLDER_MEMBER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("remove_folder_member_error");
            m_remove_folder_member_error.toJson(js, "remove_folder_member_error");
        }break;
        case JobError_RELINQUISH_FOLDER_MEMBERSHIP_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("relinquish_folder_membership_error");
            m_relinquish_folder_membership_error.toJson(js, "relinquish_folder_membership_error");
        }break;
        case JobError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void JobError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("unshare_folder_error") == 0){
        m_tag = JobError_UNSHARE_FOLDER_ERROR;
        m_unshare_folder_error.fromJson(js["unshare_folder_error"].toObject());
    }
    else if(s.compare("remove_folder_member_error") == 0){
        m_tag = JobError_REMOVE_FOLDER_MEMBER_ERROR;
        m_remove_folder_member_error.fromJson(js["remove_folder_member_error"].toObject());
    }
    else if(s.compare("relinquish_folder_membership_error") == 0){
        m_tag = JobError_RELINQUISH_FOLDER_MEMBERSHIP_ERROR;
        m_relinquish_folder_membership_error.fromJson(js["relinquish_folder_membership_error"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = JobError_OTHER;

    }
}

QString JobError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "JobError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<JobError>  JobError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<JobError> rv = std::unique_ptr<JobError>(new JobError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
