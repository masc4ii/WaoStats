/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingUnmountFolderError.h"

namespace dropboxQt{

namespace sharing{
///UnmountFolderError

UnmountFolderError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void UnmountFolderError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case UnmountFolderError_ACCESS_ERROR:{
            if(!name.isEmpty())
                js[name] = QString("access_error");
            m_access_error.toJson(js, "access_error");
        }break;
        case UnmountFolderError_NO_PERMISSION:{
            if(!name.isEmpty())
                js[name] = QString("no_permission");
        }break;
        case UnmountFolderError_NOT_UNMOUNTABLE:{
            if(!name.isEmpty())
                js[name] = QString("not_unmountable");
        }break;
        case UnmountFolderError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void UnmountFolderError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("access_error") == 0){
        m_tag = UnmountFolderError_ACCESS_ERROR;
        m_access_error.fromJson(js["access_error"].toObject());
    }
    else if(s.compare("no_permission") == 0){
        m_tag = UnmountFolderError_NO_PERMISSION;

    }
    else if(s.compare("not_unmountable") == 0){
        m_tag = UnmountFolderError_NOT_UNMOUNTABLE;

    }
    else if(s.compare("other") == 0){
        m_tag = UnmountFolderError_OTHER;

    }
}

QString UnmountFolderError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "UnmountFolderError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<UnmountFolderError>  UnmountFolderError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<UnmountFolderError> rv = std::unique_ptr<UnmountFolderError>(new UnmountFolderError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
