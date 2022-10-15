/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingListSharedLinksError.h"

namespace dropboxQt{

namespace sharing{
///ListSharedLinksError

ListSharedLinksError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListSharedLinksError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListSharedLinksError_PATH:{
            if(!name.isEmpty())
                js[name] = QString("path");
            m_path.toJson(js, "path");
        }break;
        case ListSharedLinksError_RESET:{
            if(!name.isEmpty())
                js[name] = QString("reset");
        }break;
        case ListSharedLinksError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListSharedLinksError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("path") == 0){
        m_tag = ListSharedLinksError_PATH;
        m_path.fromJson(js["path"].toObject());
    }
    else if(s.compare("reset") == 0){
        m_tag = ListSharedLinksError_RESET;

    }
    else if(s.compare("other") == 0){
        m_tag = ListSharedLinksError_OTHER;

    }
}

QString ListSharedLinksError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListSharedLinksError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListSharedLinksError>  ListSharedLinksError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListSharedLinksError> rv = std::unique_ptr<ListSharedLinksError>(new ListSharedLinksError);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
