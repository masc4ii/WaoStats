/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingSharedLinkPolicy.h"

namespace dropboxQt{

namespace sharing{
///SharedLinkPolicy

SharedLinkPolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void SharedLinkPolicy::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case SharedLinkPolicy_ANYONE:{
            if(!name.isEmpty())
                js[name] = QString("anyone");
        }break;
        case SharedLinkPolicy_MEMBERS:{
            if(!name.isEmpty())
                js[name] = QString("members");
        }break;
        case SharedLinkPolicy_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void SharedLinkPolicy::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("anyone") == 0){
        m_tag = SharedLinkPolicy_ANYONE;

    }
    else if(s.compare("members") == 0){
        m_tag = SharedLinkPolicy_MEMBERS;

    }
    else if(s.compare("other") == 0){
        m_tag = SharedLinkPolicy_OTHER;

    }
}

QString SharedLinkPolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "SharedLinkPolicy");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<SharedLinkPolicy>  SharedLinkPolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<SharedLinkPolicy> rv = std::unique_ptr<SharedLinkPolicy>(new SharedLinkPolicy);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
