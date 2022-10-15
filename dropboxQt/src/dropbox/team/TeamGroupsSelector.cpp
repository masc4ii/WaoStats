/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupsSelector.h"

namespace dropboxQt{

namespace team{
///GroupsSelector

GroupsSelector::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupsSelector::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupsSelector_GROUP_IDS:{
            if(!name.isEmpty())
                js[name] = QString("group_ids");
            js["group_ids"] = ingrl_list2jsonarray(m_group_ids);
        }break;
        case GroupsSelector_GROUP_EXTERNAL_IDS:{
            if(!name.isEmpty())
                js[name] = QString("group_external_ids");
            js["group_external_ids"] = ingrl_list2jsonarray(m_group_external_ids);
        }break;
    }//switch
}

void GroupsSelector::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("group_ids") == 0){
        m_tag = GroupsSelector_GROUP_IDS;
        jsonarray2ingrl_list(js["group_ids"].toArray(), m_group_ids);
    }
    else if(s.compare("group_external_ids") == 0){
        m_tag = GroupsSelector_GROUP_EXTERNAL_IDS;
        jsonarray2ingrl_list(js["group_external_ids"].toArray(), m_group_external_ids);
    }
}

QString GroupsSelector::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupsSelector");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupsSelector>  GroupsSelector::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupsSelector> rv = std::unique_ptr<GroupsSelector>(new GroupsSelector);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
