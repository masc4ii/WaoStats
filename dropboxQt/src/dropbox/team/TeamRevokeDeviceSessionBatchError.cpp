/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeDeviceSessionBatchError.h"

namespace dropboxQt{

namespace team{
///RevokeDeviceSessionBatchError

RevokeDeviceSessionBatchError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RevokeDeviceSessionBatchError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RevokeDeviceSessionBatchError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RevokeDeviceSessionBatchError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("other") == 0){
        m_tag = RevokeDeviceSessionBatchError_OTHER;

    }
}

QString RevokeDeviceSessionBatchError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RevokeDeviceSessionBatchError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RevokeDeviceSessionBatchError>  RevokeDeviceSessionBatchError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RevokeDeviceSessionBatchError> rv = std::unique_ptr<RevokeDeviceSessionBatchError>(new RevokeDeviceSessionBatchError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
