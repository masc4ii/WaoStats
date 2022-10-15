/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesWriteMode.h"

namespace dropboxQt{

namespace files{
///WriteMode

WriteMode::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void WriteMode::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case WriteMode_ADD:{
            if(!name.isEmpty())
                js[name] = QString("add");
        }break;
        case WriteMode_OVERWRITE:{
            if(!name.isEmpty())
                js[name] = QString("overwrite");
        }break;
        case WriteMode_UPDATE:{
            if(!name.isEmpty())
                js[name] = QString("update");
            if(!m_update.isEmpty())
                js["update"] = QString(m_update);
        }break;
    }//switch
}

void WriteMode::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("add") == 0){
        m_tag = WriteMode_ADD;

    }
    else if(s.compare("overwrite") == 0){
        m_tag = WriteMode_OVERWRITE;

    }
    else if(s.compare("update") == 0){
        m_tag = WriteMode_UPDATE;
        m_update = js["update"].toString();
    }
}

QString WriteMode::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "WriteMode");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<WriteMode>  WriteMode::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<WriteMode> rv = std::unique_ptr<WriteMode>(new WriteMode);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
