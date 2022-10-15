/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team_policies"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team_policies/TeamPoliciesSharedLinkCreatePolicy.h"

namespace dropboxQt{

namespace team_policies{
///SharedLinkCreatePolicy

SharedLinkCreatePolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedLinkCreatePolicy::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedLinkCreatePolicy_DEFAULT_PUBLIC:{
            if(!name.isEmpty())
                js[name] = QString("default_public");
        }break;
        case SharedLinkCreatePolicy_DEFAULT_TEAM_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("default_team_only");
        }break;
        case SharedLinkCreatePolicy_TEAM_ONLY:{
            if(!name.isEmpty())
                js[name] = QString("team_only");
        }break;
        case SharedLinkCreatePolicy_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedLinkCreatePolicy::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("default_public") == 0){
        m_tag = SharedLinkCreatePolicy_DEFAULT_PUBLIC;

    }
    else if(s.compare("default_team_only") == 0){
        m_tag = SharedLinkCreatePolicy_DEFAULT_TEAM_ONLY;

    }
    else if(s.compare("team_only") == 0){
        m_tag = SharedLinkCreatePolicy_TEAM_ONLY;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedLinkCreatePolicy_OTHER;

    }
}

QString SharedLinkCreatePolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedLinkCreatePolicy");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedLinkCreatePolicy>  SharedLinkCreatePolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedLinkCreatePolicy> rv = std::unique_ptr<SharedLinkCreatePolicy>(new SharedLinkCreatePolicy);
    rv->fromJson(js);
    return rv;
}

}//team_policies
}//dropboxQt
