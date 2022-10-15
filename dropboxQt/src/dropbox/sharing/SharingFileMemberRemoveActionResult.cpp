/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingFileMemberRemoveActionResult.h"

namespace dropboxQt{

namespace sharing{
///FileMemberRemoveActionResult

FileMemberRemoveActionResult::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void FileMemberRemoveActionResult::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case FileMemberRemoveActionResult_SUCCESS:{
            if(!name.isEmpty())
                js[name] = QString("success");
            js["success"] = (QJsonObject)m_success;
        }break;
        case FileMemberRemoveActionResult_MEMBER_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("member_error");
            m_member_error.toJson(js, "member_error");
        }break;
        case FileMemberRemoveActionResult_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void FileMemberRemoveActionResult::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("success") == 0){
        m_tag = FileMemberRemoveActionResult_SUCCESS;
        m_success.fromJson(js["success"].toObject());
    }
    else if(s.compare("member_error") == 0){
        m_tag = FileMemberRemoveActionResult_MEMBER_ERROR;
        m_member_error.fromJson(js["member_error"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = FileMemberRemoveActionResult_OTHER;

    }
}

QString FileMemberRemoveActionResult::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "FileMemberRemoveActionResult");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<FileMemberRemoveActionResult>  FileMemberRemoveActionResult::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<FileMemberRemoveActionResult> rv = std::unique_ptr<FileMemberRemoveActionResult>(new FileMemberRemoveActionResult);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
