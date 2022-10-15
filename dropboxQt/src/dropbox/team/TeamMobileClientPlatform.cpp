/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMobileClientPlatform.h"

namespace dropboxQt{

namespace team{
///MobileClientPlatform

MobileClientPlatform::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MobileClientPlatform::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MobileClientPlatform_IPHONE:{
            if(!name.isEmpty())
                js[name] = QString("iphone");
        }break;
        case MobileClientPlatform_IPAD:{
            if(!name.isEmpty())
                js[name] = QString("ipad");
        }break;
        case MobileClientPlatform_ANDROID:{
            if(!name.isEmpty())
                js[name] = QString("android");
        }break;
        case MobileClientPlatform_WINDOWS_PHONE:{
            if(!name.isEmpty())
                js[name] = QString("windows_phone");
        }break;
        case MobileClientPlatform_BLACKBERRY:{
            if(!name.isEmpty())
                js[name] = QString("blackberry");
        }break;
        case MobileClientPlatform_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MobileClientPlatform::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("iphone") == 0){
        m_tag = MobileClientPlatform_IPHONE;

    }
    else if(s.compare("ipad") == 0){
        m_tag = MobileClientPlatform_IPAD;

    }
    else if(s.compare("android") == 0){
        m_tag = MobileClientPlatform_ANDROID;

    }
    else if(s.compare("windows_phone") == 0){
        m_tag = MobileClientPlatform_WINDOWS_PHONE;

    }
    else if(s.compare("blackberry") == 0){
        m_tag = MobileClientPlatform_BLACKBERRY;

    }
    else if(s.compare("other") == 0){
        m_tag = MobileClientPlatform_OTHER;

    }
}

QString MobileClientPlatform::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MobileClientPlatform");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MobileClientPlatform>  MobileClientPlatform::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MobileClientPlatform> rv = std::unique_ptr<MobileClientPlatform>(new MobileClientPlatform);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
