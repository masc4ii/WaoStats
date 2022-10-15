/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingGetSharedLinksError.h"

namespace dropboxQt{

namespace sharing{
///GetSharedLinksError

GetSharedLinksError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetSharedLinksError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetSharedLinksError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            if(!m_path.isEmpty())
                js["path"] = QString(m_path);
        }break;
        case GetSharedLinksError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetSharedLinksError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = GetSharedLinksError_PATH;
        m_path = js["path"].toString();
    }
    else if(s.compare("other") == 0){
        m_tag = GetSharedLinksError_OTHER;

    }
}

QString GetSharedLinksError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetSharedLinksError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetSharedLinksError>  GetSharedLinksError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetSharedLinksError> rv = std::unique_ptr<GetSharedLinksError>(new GetSharedLinksError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
