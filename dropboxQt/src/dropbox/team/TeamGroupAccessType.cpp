/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupAccessType.h"

namespace dropboxQt{

namespace team{
///GroupAccessType

GroupAccessType::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupAccessType::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupAccessType_MEMBER:{
            if(!name.isEmpty())
                js[name] = QString("member");
        }break;
        case GroupAccessType_OWNER:{
            if(!name.isEmpty())
                js[name] = QString("owner");
        }break;
    }//switch
}

void GroupAccessType::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("member") == 0){
        m_tag = GroupAccessType_MEMBER;

    }
    else if(s.compare("owner") == 0){
        m_tag = GroupAccessType_OWNER;

    }
}

QString GroupAccessType::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupAccessType");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupAccessType>  GroupAccessType::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupAccessType> rv = std::unique_ptr<GroupAccessType>(new GroupAccessType);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
