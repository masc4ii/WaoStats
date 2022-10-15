/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesDownloadError.h"

namespace dropboxQt{

namespace files{
///DownloadError

DownloadError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void DownloadError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case DownloadError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case DownloadError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void DownloadError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = DownloadError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = DownloadError_OTHER;

    }
}

QString DownloadError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "DownloadError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<DownloadError>  DownloadError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<DownloadError> rv = std::unique_ptr<DownloadError>(new DownloadError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
