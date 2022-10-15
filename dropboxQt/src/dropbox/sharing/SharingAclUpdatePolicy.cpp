/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAclUpdatePolicy.h"

namespace dropboxQt{

namespace sharing{
///AclUpdatePolicy

AclUpdatePolicy::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AclUpdatePolicy::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AclUpdatePolicy_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("owner");
        }break;
        case AclUpdatePolicy_EDITORS:{
            if(!name.isEmpty())
                js[name] = QString("editors");
        }break;
        case AclUpdatePolicy_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void AclUpdatePolicy::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("owner") == 0){
        m_tag = AclUpdatePolicy_OWNER;

    }
    else if(s.compare("editors") == 0){
        m_tag = AclUpdatePolicy_EDITORS;

    }
    else if(s.compare("other") == 0){
        m_tag = AclUpdatePolicy_OTHER;

    }
}

QString AclUpdatePolicy::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AclUpdatePolicy");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AclUpdatePolicy>  AclUpdatePolicy::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AclUpdatePolicy> rv = std::unique_ptr<AclUpdatePolicy>(new AclUpdatePolicy);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
