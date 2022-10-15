/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingPendingUploadMode.h"

namespace dropboxQt{

namespace sharing{
///PendingUploadMode

PendingUploadMode::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void PendingUploadMode::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PendingUploadMode_FILE:{
            if(!name.isEmpty())
                js[name] = QString("file");
        }break;
        case PendingUploadMode_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("folder");
        }break;
    }//switch
}

void PendingUploadMode::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("file") == 0){
        m_tag = PendingUploadMode_FILE;

    }
    else if(s.compare("folder") == 0){
        m_tag = PendingUploadMode_FOLDER;

    }
}

QString PendingUploadMode::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "PendingUploadMode");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<PendingUploadMode>  PendingUploadMode::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<PendingUploadMode> rv = std::unique_ptr<PendingUploadMode>(new PendingUploadMode);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
