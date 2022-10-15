/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingResolvedVisibility.h"

namespace dropboxQt{

namespace sharing{
///ResolvedVisibility

ResolvedVisibility::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ResolvedVisibility::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case RequestedVisibility_PUBLIC:{
            if(!name.isEmpty())
                js[name] = QString("public");
        }break;
        case RequestedVisibility_TEAM_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("team_only");
        }break;
        case RequestedVisibility_PASSWORD:{
            if(!name.isEmpty())
                js[name] = QString("password");
        }break;
        case ResolvedVisibility_TEAM_AND_PASSWORD:{
            if(!name.isEmpty())
                js[name] = QString("team_and_password");
        }break;
        case ResolvedVisibility_SHARED_FOLDER_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("shared_folder_only");
        }break;
        case ResolvedVisibility_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ResolvedVisibility::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("public") == 0){
        m_tag = RequestedVisibility_PUBLIC;

    }
    else if(s.compare("team_only") == 0){
        m_tag = RequestedVisibility_TEAM_ONLY;

    }
    else if(s.compare("password") == 0){
        m_tag = RequestedVisibility_PASSWORD;

    }
    if(s.compare("team_and_password") == 0){
        m_tag = ResolvedVisibility_TEAM_AND_PASSWORD;

    }
    else if(s.compare("shared_folder_only") == 0){
        m_tag = ResolvedVisibility_SHARED_FOLDER_ONLY;

    }
    else if(s.compare("other") == 0){
        m_tag = ResolvedVisibility_OTHER;

    }
}

QString ResolvedVisibility::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ResolvedVisibility");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ResolvedVisibility>  ResolvedVisibility::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ResolvedVisibility> rv = std::unique_ptr<ResolvedVisibility>(new ResolvedVisibility);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
