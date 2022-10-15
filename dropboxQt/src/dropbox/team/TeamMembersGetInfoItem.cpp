/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersGetInfoItem.h"

namespace dropboxQt{

namespace team{
///MembersGetInfoItem

MembersGetInfoItem::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersGetInfoItem::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MembersGetInfoItem_ID_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("id_not_found");
            if(!m_id_not_found.isEmpty())
                js["id_not_found"] = QString(m_id_not_found);
        }break;
        case MembersGetInfoItem_MEMBER_INFO:{
            if(!name.isEmpty())
                js[name] = QString("member_info");
            js["member_info"] = (QJsonObject)m_member_info;
        }break;
    }//switch
}

void MembersGetInfoItem::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("id_not_found") == 0){
        m_tag = MembersGetInfoItem_ID_NOT_FOUND;
        m_id_not_found = js["id_not_found"].toString();
    }
    else if(s.compare("member_info") == 0){
        m_tag = MembersGetInfoItem_MEMBER_INFO;
        m_member_info.fromJson(js["member_info"].toObject());
    }
}

QString MembersGetInfoItem::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersGetInfoItem");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersGetInfoItem>  MembersGetInfoItem::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersGetInfoItem> rv = std::unique_ptr<MembersGetInfoItem>(new MembersGetInfoItem);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
