/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesThumbnailError.h"

namespace dropboxQt{

namespace files{
///ThumbnailError

ThumbnailError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ThumbnailError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ThumbnailError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case ThumbnailError_UNSUPPORTED_EXTENSION:{
            if(!name.isEmpty())
                js[name] = QString("unsupported_extension");
        }break;
        case ThumbnailError_UNSUPPORTED_IMAGE:{
            if(!name.isEmpty())
                js[name] = QString("unsupported_image");
        }break;
        case ThumbnailError_CONVERSION_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("conversion_error");
        }break;
    }//switch
}

void ThumbnailError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = ThumbnailError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("unsupported_extension") == 0){
        m_tag = ThumbnailError_UNSUPPORTED_EXTENSION;

    }
    else if(s.compare("unsupported_image") == 0){
        m_tag = ThumbnailError_UNSUPPORTED_IMAGE;

    }
    else if(s.compare("conversion_error") == 0){
        m_tag = ThumbnailError_CONVERSION_ERROR;

    }
}

QString ThumbnailError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ThumbnailError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ThumbnailError>  ThumbnailError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ThumbnailError> rv = std::unique_ptr<ThumbnailError>(new ThumbnailError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
