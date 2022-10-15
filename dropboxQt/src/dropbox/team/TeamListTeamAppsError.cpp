/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListTeamAppsError.h"

namespace dropboxQt{

namespace team{
///ListTeamAppsError

ListTeamAppsError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListTeamAppsError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListTeamAppsError_RESET:{
            if(!name.isEmpty())
                js[name] = QString("reset");
        }break;
        case ListTeamAppsError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListTeamAppsError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("reset") == 0){
        m_tag = ListTeamAppsError_RESET;

    }
    else if(s.compare("other") == 0){
        m_tag = ListTeamAppsError_OTHER;

    }
}

QString ListTeamAppsError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListTeamAppsError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListTeamAppsError>  ListTeamAppsError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListTeamAppsError> rv = std::unique_ptr<ListTeamAppsError>(new ListTeamAppsError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
