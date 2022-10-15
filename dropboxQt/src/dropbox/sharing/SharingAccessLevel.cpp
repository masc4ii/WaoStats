/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "sharing"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/sharing/SharingAccessLevel.h"

namespace dropboxQt{

namespace sharing{
///AccessLevel

AccessLevel::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void AccessLevel::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case AccessLevel_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("owner");
        }break;
        case AccessLevel_EDITOR:{
            if(!name.isEmpty())
                js[name] = QString("editor");
        }break;
        case AccessLevel_VIEWER:{
            if(!name.isEmpty())
                js[name] = QString("viewer");
        }break;
        case AccessLevel_VIEWER_NO_COMMENT:{
            if(!name.isEmpty())
                js[name] = QString("viewer_no_comment");
        }break;
        case AccessLevel_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void AccessLevel::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("owner") == 0){
        m_tag = AccessLevel_OWNER;

    }
    else if(s.compare("editor") == 0){
        m_tag = AccessLevel_EDITOR;

    }
    else if(s.compare("viewer") == 0){
        m_tag = AccessLevel_VIEWER;

    }
    else if(s.compare("viewer_no_comment") == 0){
        m_tag = AccessLevel_VIEWER_NO_COMMENT;

    }
    else if(s.compare("other") == 0){
        m_tag = AccessLevel_OTHER;

    }
}

QString AccessLevel::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "AccessLevel");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<AccessLevel>  AccessLevel::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<AccessLevel> rv = std::unique_ptr<AccessLevel>(new AccessLevel);
    rv->fromJson(js);
    return rv;
}

}//sharing
}//dropboxQt
