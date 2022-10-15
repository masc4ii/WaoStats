/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupCreateError.h"

namespace dropboxQt{

namespace team{
///GroupCreateError

GroupCreateError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupCreateError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupCreateError_GROUP_NAME_ALREADY_USED:{
            if(!name.isEmpty())
                js[name] = QString("group_name_already_used");
        }break;
        case GroupCreateError_GROUP_NAME_INVALID:{
            if(!name.isEmpty())
                js[name] = QString("group_name_invalid");
        }break;
        case GroupCreateError_EXTERNAL_ID_ALREADY_IN_USE:{
            if(!name.isEmpty())
                js[name] = QString("external_id_already_in_use");
        }break;
        case GroupCreateError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void GroupCreateError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("group_name_already_used") == 0){
        m_tag = GroupCreateError_GROUP_NAME_ALREADY_USED;

    }
    else if(s.compare("group_name_invalid") == 0){
        m_tag = GroupCreateError_GROUP_NAME_INVALID;

    }
    else if(s.compare("external_id_already_in_use") == 0){
        m_tag = GroupCreateError_EXTERNAL_ID_ALREADY_IN_USE;

    }
    else if(s.compare("other") == 0){
        m_tag = GroupCreateError_OTHER;

    }
}

QString GroupCreateError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupCreateError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupCreateError>  GroupCreateError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupCreateError> rv = std::unique_ptr<GroupCreateError>(new GroupCreateError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
