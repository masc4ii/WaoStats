/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "users"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/users/UsersSpaceAllocation.h"

namespace dropboxQt{

namespace users{
///SpaceAllocation

SpaceAllocation::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SpaceAllocation::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SpaceAllocation_INDIVIDUAL:{
            if(!name.isEmpty())
                js[name] = QString("individual");
            js["individual"] = (QJsonObject)m_individual;
        }break;
        case SpaceAllocation_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("team");
            js["team"] = (QJsonObject)m_team;
        }break;
        case SpaceAllocation_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SpaceAllocation::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("individual") == 0){
        m_tag = SpaceAllocation_INDIVIDUAL;
        m_individual.fromJson(js["individual"].toObject());
    }
    else if(s.compare("team") == 0){
        m_tag = SpaceAllocation_TEAM;
        m_team.fromJson(js["team"].toObject());
    }
    else if(s.compare("other") == 0){
        m_tag = SpaceAllocation_OTHER;

    }
}

QString SpaceAllocation::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SpaceAllocation");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SpaceAllocation>  SpaceAllocation::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SpaceAllocation> rv = std::unique_ptr<SpaceAllocation>(new SpaceAllocation);
    rv->fromJson(js);
    return rv;
}

}//users
}//dropboxQt
