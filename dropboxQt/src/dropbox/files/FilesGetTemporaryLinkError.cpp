/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesGetTemporaryLinkError.h"

namespace dropboxQt{

namespace files{
///GetTemporaryLinkError

GetTemporaryLinkError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetTemporaryLinkError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetTemporaryLinkError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case GetTemporaryLinkError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetTemporaryLinkError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = GetTemporaryLinkError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = GetTemporaryLinkError_OTHER;

    }
}

QString GetTemporaryLinkError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetTemporaryLinkError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetTemporaryLinkError>  GetTemporaryLinkError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetTemporaryLinkError> rv = std::unique_ptr<GetTemporaryLinkError>(new GetTemporaryLinkError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
