/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingCreateSharedLinkError.h"

namespace dropboxQt{

namespace sharing{
///CreateSharedLinkError

CreateSharedLinkError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void CreateSharedLinkError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case CreateSharedLinkError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case CreateSharedLinkError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void CreateSharedLinkError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = CreateSharedLinkError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = CreateSharedLinkError_OTHER;

    }
}

QString CreateSharedLinkError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "CreateSharedLinkError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<CreateSharedLinkError>  CreateSharedLinkError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<CreateSharedLinkError> rv = std::unique_ptr<CreateSharedLinkError>(new CreateSharedLinkError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
