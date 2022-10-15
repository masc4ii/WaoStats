/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersListError.h"

namespace dropboxQt{

namespace team{
///MembersListError

MembersListError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersListError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MembersListError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MembersListError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("other") == 0){
        m_tag = MembersListError_OTHER;

    }
}

QString MembersListError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersListError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersListError>  MembersListError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersListError> rv = std::unique_ptr<MembersListError>(new MembersListError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
