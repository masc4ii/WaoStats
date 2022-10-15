/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "files"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/files/FilesRelocationError.h"

namespace dropboxQt{

namespace files{
///RelocationError

RelocationError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void RelocationError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RelocationError_FROM_LOOKUP:{
            if(!name.isEmpty())
                js[name] = QString("from_lookup");
            m_from_lookup.toJson(js, "from_lookup");
        }break;
        case RelocationError_FROM_WRITE:{
            if(!name.isEmpty())
                js[name] = QString("from_write");
            m_from_write.toJson(js, "from_write");
        }break;
        case RelocationError_TO:{
            if(!name.isEmpty())
                js[name] = QString("to");
            m_to.toJson(js, "to");
        }break;
        case RelocationError_CANT_COPY_SHARED_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("cant_copy_shared_folder");
        }break;
        case RelocationError_CANT_NEST_SHARED_FOLDER:{
            if(!name.isEmpty())
                js[name] = QString("cant_nest_shared_folder");
        }break;
        case RelocationError_CANT_MOVE_FOLDER_INTO_ITSELF:{
            if(!name.isEmpty())
                js[name] = QString("cant_move_folder_into_itself");
        }break;
        case RelocationError_TOO_MANY_FILES:{
            if(!name.isEmpty())
                js[name] = QString("too_many_files");
        }break;
        case RelocationError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void RelocationError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("from_lookup") == 0){
        m_tag = RelocationError_FROM_LOOKUP;
        m_from_lookup.fromJson(js["from_lookup"].toObject());
    }
    else if(s.compare("from_write") == 0){
        m_tag = RelocationError_FROM_WRITE;
        m_from_write.fromJson(js["from_write"].toObject());
    }
    else if(s.compare("to") == 0){
        m_tag = RelocationError_TO;
        m_to.fromJson(js["to"].toObject());
    }
    else if(s.compare("cant_copy_shared_folder") == 0){
        m_tag = RelocationError_CANT_COPY_SHARED_FOLDER;

    }
    else if(s.compare("cant_nest_shared_folder") == 0){
        m_tag = RelocationError_CANT_NEST_SHARED_FOLDER;

    }
    else if(s.compare("cant_move_folder_into_itself") == 0){
        m_tag = RelocationError_CANT_MOVE_FOLDER_INTO_ITSELF;

    }
    else if(s.compare("too_many_files") == 0){
        m_tag = RelocationError_TOO_MANY_FILES;

    }
    else if(s.compare("other") == 0){
        m_tag = RelocationError_OTHER;

    }
}

QString RelocationError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "RelocationError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<RelocationError>  RelocationError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<RelocationError> rv = std::unique_ptr<RelocationError>(new RelocationError);
    rv->fromJson(js);
    return rv;
}

}//files
}//dropboxQt
