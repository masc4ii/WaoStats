/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "team"
 Part of "Ardi - the organizer" project.
 osoft4ardi@gmail.com
 www.prokarpaty.net
***********************************************************/

#include "dropbox/team/TeamMembersGetInfoError.h"

namespace dropboxQt{

namespace team{
///MembersGetInfoError

MembersGetInfoError::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js, "");
    return js;
}


void MembersGetInfoError::toJson(QJsonObject& js, QString name)const{

    switch(m_tag){
        case MembersGetInfoError_OTHER:{
            if(!name.isEmpty())
                js[name] = QString("other");
        }break;
    }//switch
}

void MembersGetInfoError::fromJson(const QJsonObject& js){

    QString s = js[".tag"].toString();
    if(s.compare("other") == 0){
        m_tag = MembersGetInfoError_OTHER;

    }
}

QString MembersGetInfoError::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js, "MembersGetInfoError");
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}

std::unique_ptr<MembersGetInfoError>  MembersGetInfoError::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    std::unique_ptr<MembersGetInfoError> rv = std::unique_ptr<MembersGetInfoError>(new MembersGetInfoError);
    rv->fromJson(js);
    return rv;
}

}//team
}//dropboxQt
