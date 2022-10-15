/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMembersDevicesError.h"

namespace dropboxQt{

namespace team{
///ListMembersDevicesError

ListMembersDevicesError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListMembersDevicesError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListMembersDevicesError_RESET:{
            if(!name.isEmpty())
                js[name] = QString("reset");
        }break;
        case ListMembersDevicesError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListMembersDevicesError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("reset") == 0){
        m_tag = ListMembersDevicesError_RESET;

    }
    else if(s.compare("other") == 0){
        m_tag = ListMembersDevicesError_OTHER;

    }
}

QString ListMembersDevicesError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListMembersDevicesError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListMembersDevicesError>  ListMembersDevicesError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListMembersDevicesError> rv = std::unique_ptr<ListMembersDevicesError>(new ListMembersDevicesError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
