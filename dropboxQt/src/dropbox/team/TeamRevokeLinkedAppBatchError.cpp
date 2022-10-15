/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamRevokeLinkedAppBatchError.h"

namespace dropboxQt{

namespace team{
///RevokeLinkedAppBatchError

RevokeLinkedAppBatchError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RevokeLinkedAppBatchError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RevokeLinkedAppBatchError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RevokeLinkedAppBatchError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("other") == 0){
        m_tag = RevokeLinkedAppBatchError_OTHER;

    }
}

QString RevokeLinkedAppBatchError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RevokeLinkedAppBatchError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RevokeLinkedAppBatchError>  RevokeLinkedAppBatchError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RevokeLinkedAppBatchError> rv = std::unique_ptr<RevokeLinkedAppBatchError>(new RevokeLinkedAppBatchError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
