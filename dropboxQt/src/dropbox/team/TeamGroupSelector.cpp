/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamGroupSelector.h"

namespace dropboxQt{

namespace team{
///GroupSelector

GroupSelector::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void GroupSelector::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case GroupSelector_GROUP_ID:{
            if(!name.isEmpty())
                js[name] = QString("group_id");
            if(!m_group_id.isEmpty())
                js["group_id"] = QString(m_group_id);
        }break;
        case GroupSelector_GROUP_EXTERNAL_ID:{
            if(!name.isEmpty())
                js[name] = QString("group_external_id");
            if(!m_group_external_id.isEmpty())
                js["group_external_id"] = QString(m_group_external_id);
        }break;
    }//switch
}

void GroupSelector::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("group_id") == 0){
        m_tag = GroupSelector_GROUP_ID;
        m_group_id = js["group_id"].toString();
    }
    else if(s.compare("group_external_id") == 0){
        m_tag = GroupSelector_GROUP_EXTERNAL_ID;
        m_group_external_id = js["group_external_id"].toString();
    }
}

QString GroupSelector::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "GroupSelector");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<GroupSelector>  GroupSelector::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<GroupSelector> rv = std::unique_ptr<GroupSelector>(new GroupSelector);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
