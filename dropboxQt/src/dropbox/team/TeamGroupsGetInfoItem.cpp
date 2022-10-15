/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsGetInfoItem.h"

namespace dropboxQt{

namespace team{
///GroupsGetInfoItem

GroupsGetInfoItem::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupsGetInfoItem::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupsGetInfoItem_ID_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("id_not_found");
            if(!m_id_not_found.isEmpty())
                js["id_not_found"] = QString(m_id_not_found);
        }break;
        case GroupsGetInfoItem_GROUP_INFO:{
            if(!name.isEmpty())
                js[name] = QString("group_info");
            js["group_info"] = (QJsonObject)m_group_info;
        }break;
    }//switch
}

void GroupsGetInfoItem::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("id_not_found") == 0){
        m_tag = GroupsGetInfoItem_ID_NOT_FOUND;
        m_id_not_found = js["id_not_found"].toString();
    }
    else if(s.compare("group_info") == 0){
        m_tag = GroupsGetInfoItem_GROUP_INFO;
        m_group_info.fromJson(js["group_info"].toObject());
    }
}

QString GroupsGetInfoItem::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupsGetInfoItem");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupsGetInfoItem>  GroupsGetInfoItem::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupsGetInfoItem> rv = std::unique_ptr<GroupsGetInfoItem>(new GroupsGetInfoItem);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
