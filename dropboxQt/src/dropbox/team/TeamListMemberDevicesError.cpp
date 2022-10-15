/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMemberDevicesError.h"

namespace dropboxQt{

namespace team{
///ListMemberDevicesError

ListMemberDevicesError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListMemberDevicesError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListMemberDevicesError_MEMBER_NOT_FOUND:{
            if(!name.isEmpty())
                js[name] = QString("member_not_found");
        }break;
        case ListMemberDevicesError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListMemberDevicesError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("member_not_found") == 0){
        m_tag = ListMemberDevicesError_MEMBER_NOT_FOUND;

    }
    else if(s.compare("other") == 0){
        m_tag = ListMemberDevicesError_OTHER;

    }
}

QString ListMemberDevicesError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListMemberDevicesError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListMemberDevicesError>  ListMemberDevicesError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListMemberDevicesError> rv = std::unique_ptr<ListMemberDevicesError>(new ListMemberDevicesError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
