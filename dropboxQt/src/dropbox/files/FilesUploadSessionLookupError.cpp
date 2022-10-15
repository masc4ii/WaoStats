/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesUploadSessionLookupError.h"

namespace dropboxQt{

namespace files{
///UploadSessionLookupError

UploadSessionLookupError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UploadSessionLookupError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UploadSessionLookupError_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("not_found");
        }break;
        case UploadSessionLookupError_INCORRECT_OFFSET:{
            if(!name.isEmpty())
                js[name] = QString("incorrect_offset");
            js["incorrect_offset"] = (QJsonObject)m_incorrect_offset;
        }break;
        case UploadSessionLookupError_CLOSED:{
            if(!name.isEmpty())
                js[name] = QString("closed");
        }break;
        case UploadSessionLookupError_NOT_CLOSED:{
            if(!name.isEmpty())
                js[name] = QString("not_closed");
        }break;
        case UploadSessionLookupError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void UploadSessionLookupError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("not_found") == 0){
        m_tag = UploadSessionLookupError_NOT_FOUND;

    }
    else if(s.compare("incorrect_offset") == 0){
        m_tag = UploadSessionLookupError_INCORRECT_OFFSET;
        m_incorrect_offset.fromJson(js["incorrect_offset"].toObject());
    }
    else if(s.compare("closed") == 0){
        m_tag = UploadSessionLookupError_CLOSED;

    }
    else if(s.compare("not_closed") == 0){
        m_tag = UploadSessionLookupError_NOT_CLOSED;

    }
    else if(s.compare("other") == 0){
        m_tag = UploadSessionLookupError_OTHER;

    }
}

QString UploadSessionLookupError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UploadSessionLookupError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UploadSessionLookupError>  UploadSessionLookupError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UploadSessionLookupError> rv = std::unique_ptr<UploadSessionLookupError>(new UploadSessionLookupError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
