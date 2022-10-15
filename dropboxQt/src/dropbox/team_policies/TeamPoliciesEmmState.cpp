/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team_policies/TeamPoliciesEmmState.h"

namespace dropboxQt{

namespace team_policies{
///EmmState

EmmState::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void EmmState::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case EmmState_DISABLED:{
            if(!name.isEmpty())
                js[name] = QString("disabled");
        }break;
        case EmmState_OPTIONAL:{
            if(!name.isEmpty())
                js[name] = QString("optional");
        }break;
        case EmmState_REQUIRED:{
            if(!name.isEmpty())
                js[name] = QString("required");
        }break;
        case EmmState_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void EmmState::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("disabled") == 0){
        m_tag = EmmState_DISABLED;

    }
    else if(s.compare("optional") == 0){
        m_tag = EmmState_OPTIONAL;

    }
    else if(s.compare("required") == 0){
        m_tag = EmmState_REQUIRED;

    }
    else if(s.compare("other") == 0){
        m_tag = EmmState_OTHER;

    }
}

QString EmmState::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "EmmState");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<EmmState>  EmmState::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<EmmState> rv = std::unique_ptr<EmmState>(new EmmState);
    rv->fromJson(js);
    return rv;
}

}//team_policies
}//dropboxQt
