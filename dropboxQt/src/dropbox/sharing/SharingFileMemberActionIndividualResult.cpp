/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFileMemberActionIndividualResult.h"

namespace dropboxQt{

namespace sharing{
///FileMemberActionIndividualResult

FileMemberActionIndividualResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void FileMemberActionIndividualResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case FileMemberActionIndividualResult_SUCCESS:{
            if(!name.isEmpty())
                js[name] = QString("success");
            m_success.toJson(js, "success");
        }break;
        case FileMemberActionIndividualResult_MEMBER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("member_error");
            m_member_error.toJson(js, "member_error");
        }break;
    }//switch
}

void FileMemberActionIndividualResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("success") == 0){
        m_tag = FileMemberActionIndividualResult_SUCCESS;
        m_success.fromJson(js["success"].toObject());
    }
    else if(s.compare("member_error") == 0){
        m_tag = FileMemberActionIndividualResult_MEMBER_ERROR;
        m_member_error.fromJson(js["member_error"].toObject());
    }
}

QString FileMemberActionIndividualResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "FileMemberActionIndividualResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<FileMemberActionIndividualResult>  FileMemberActionIndividualResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<FileMemberActionIndividualResult> rv = std::unique_ptr<FileMemberActionIndividualResult>(new FileMemberActionIndividualResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
