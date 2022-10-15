/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesGetCopyReferenceError.h"

namespace dropboxQt{

namespace files{
///GetCopyReferenceError

GetCopyReferenceError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetCopyReferenceError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetCopyReferenceError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case GetCopyReferenceError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GetCopyReferenceError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = GetCopyReferenceError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = GetCopyReferenceError_OTHER;

    }
}

QString GetCopyReferenceError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetCopyReferenceError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetCopyReferenceError>  GetCopyReferenceError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetCopyReferenceError> rv = std::unique_ptr<GetCopyReferenceError>(new GetCopyReferenceError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
