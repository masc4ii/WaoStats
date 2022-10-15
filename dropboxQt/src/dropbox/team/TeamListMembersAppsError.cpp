/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamListMembersAppsError.h"

namespace dropboxQt{

namespace team{
///ListMembersAppsError

ListMembersAppsError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void ListMembersAppsError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case ListMembersAppsError_RESET:{
            if(!name.isEmpty())
                js[name] = QString("reset");
        }break;
        case ListMembersAppsError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void ListMembersAppsError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("reset") == 0){
        m_tag = ListMembersAppsError_RESET;

    }
    else if(s.compare("other") == 0){
        m_tag = ListMembersAppsError_OTHER;

    }
}

QString ListMembersAppsError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "ListMembersAppsError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<ListMembersAppsError>  ListMembersAppsError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<ListMembersAppsError> rv = std::unique_ptr<ListMembersAppsError>(new ListMembersAppsError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
