/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesPreviewError.h"

namespace dropboxQt{

namespace files{
///PreviewError

PreviewError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void PreviewError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case PreviewError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case PreviewError_IN_PROGRESS:{
            if(!name.isEmpty())
                js[name] = QString("in_progress");
        }break;
        case PreviewError_UNSUPPORTED_EXTENSION:{
            if(!name.isEmpty())
                js[name] = QString("unsupported_extension");
        }break;
        case PreviewError_UNSUPPORTED_CONTENT:{
            if(!name.isEmpty())
                js[name] = QString("unsupported_content");
        }break;
    }//switch
}

void PreviewError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = PreviewError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("in_progress") == 0){
        m_tag = PreviewError_IN_PROGRESS;

    }
    else if(s.compare("unsupported_extension") == 0){
        m_tag = PreviewError_UNSUPPORTED_EXTENSION;

    }
    else if(s.compare("unsupported_content") == 0){
        m_tag = PreviewError_UNSUPPORTED_CONTENT;

    }
}

QString PreviewError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "PreviewError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<PreviewError>  PreviewError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<PreviewError> rv = std::unique_ptr<PreviewError>(new PreviewError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
