/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamDesktopPlatform.h"

namespace dropboxQt{

namespace team{
///DesktopPlatform

DesktopPlatform::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void DesktopPlatform::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case DesktopPlatform_WINDOWS:{
            if(!name.isEmpty())
                js[name] = QString("windows");
        }break;
        case DesktopPlatform_MAC:{
            if(!name.isEmpty())
                js[name] = QString("mac");
        }break;
        case DesktopPlatform_LINUX:{
            if(!name.isEmpty())
                js[name] = QString("linux");
        }break;
        case DesktopPlatform_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void DesktopPlatform::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("windows") == 0){
        m_tag = DesktopPlatform_WINDOWS;

    }
    else if(s.compare("mac") == 0){
        m_tag = DesktopPlatform_MAC;

    }
    else if(s.compare("linux") == 0){
        m_tag = DesktopPlatform_LINUX;

    }
    else if(s.compare("other") == 0){
        m_tag = DesktopPlatform_OTHER;

    }
}

QString DesktopPlatform::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "DesktopPlatform");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<DesktopPlatform>  DesktopPlatform::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<DesktopPlatform> rv = std::unique_ptr<DesktopPlatform>(new DesktopPlatform);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
