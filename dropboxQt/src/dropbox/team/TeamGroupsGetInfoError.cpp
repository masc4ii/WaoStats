/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsGetInfoError.h"

namespace dropboxQt{

namespace team{
///GroupsGetInfoError

GroupsGetInfoError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupsGetInfoError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupsGetInfoError_GROUP_NOT_ON_TEAM:{
            if(!name.isEmpty())
                js[name] = QString("group_not_on_team");
        }break;
        case GroupsGetInfoError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GroupsGetInfoError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("group_not_on_team") == 0){
        m_tag = GroupsGetInfoError_GROUP_NOT_ON_TEAM;

    }
    else if(s.compare("other") == 0){
        m_tag = GroupsGetInfoError_OTHER;

    }
}

QString GroupsGetInfoError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupsGetInfoError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupsGetInfoError>  GroupsGetInfoError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupsGetInfoError> rv = std::unique_ptr<GroupsGetInfoError>(new GroupsGetInfoError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
