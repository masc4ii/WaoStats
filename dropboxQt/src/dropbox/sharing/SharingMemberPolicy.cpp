/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingMemberPolicy.h"

namespace dropboxQt{

namespace sharing{
///MemberPolicy

MemberPolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MemberPolicy::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MemberPolicy_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("team");
        }break;
        case MemberPolicy_ANYONE:{
            if(!name.isEmpty())
                js[name] = QString("anyone");
        }break;
        case MemberPolicy_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MemberPolicy::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("team") == 0){
        m_tag = MemberPolicy_TEAM;

    }
    else if(s.compare("anyone") == 0){
        m_tag = MemberPolicy_ANYONE;

    }
    else if(s.compare("other") == 0){
        m_tag = MemberPolicy_OTHER;

    }
}

QString MemberPolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MemberPolicy");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MemberPolicy>  MemberPolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MemberPolicy> rv = std::unique_ptr<MemberPolicy>(new MemberPolicy);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
