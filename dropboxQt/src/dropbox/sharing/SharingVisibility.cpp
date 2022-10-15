/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingVisibility.h"

namespace dropboxQt{

namespace sharing{
///Visibility

Visibility::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void Visibility::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case Visibility_PUBLIC:{
            if(!name.isEmpty())
                js[name] = QString("public");
        }break;
        case Visibility_TEAM_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("team_only");
        }break;
        case Visibility_PASSWORD:{
            if(!name.isEmpty())
                js[name] = QString("password");
        }break;
        case Visibility_TEAM_AND_PASSWORD:{
            if(!name.isEmpty())
                js[name] = QString("team_and_password");
        }break;
        case Visibility_SHARED_FOLDER_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("shared_folder_only");
        }break;
        case Visibility_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void Visibility::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("public") == 0){
        m_tag = Visibility_PUBLIC;

    }
    else if(s.compare("team_only") == 0){
        m_tag = Visibility_TEAM_ONLY;

    }
    else if(s.compare("password") == 0){
        m_tag = Visibility_PASSWORD;

    }
    else if(s.compare("team_and_password") == 0){
        m_tag = Visibility_TEAM_AND_PASSWORD;

    }
    else if(s.compare("shared_folder_only") == 0){
        m_tag = Visibility_SHARED_FOLDER_ONLY;

    }
    else if(s.compare("other") == 0){
        m_tag = Visibility_OTHER;

    }
}

QString Visibility::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "Visibility");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<Visibility>  Visibility::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<Visibility> rv = std::unique_ptr<Visibility>(new Visibility);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
