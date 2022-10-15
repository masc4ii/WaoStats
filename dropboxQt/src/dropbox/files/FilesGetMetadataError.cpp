/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesGetMetadataError.h"

namespace dropboxQt{

namespace files{
///GetMetadataError

GetMetadataError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GetMetadataError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GetMetadataError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
    }//switch
}

void GetMetadataError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = GetMetadataError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
}

QString GetMetadataError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GetMetadataError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GetMetadataError>  GetMetadataError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GetMetadataError> rv = std::unique_ptr<GetMetadataError>(new GetMetadataError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
